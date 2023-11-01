#include "toykv_service.h"

#include <vector>

#include "rpc/gensrc/Status_types.h"

namespace toykv {

void ToykvService::Insert(TDmlRes &result, const TInsertReq &request) {
    // step 1: check request
    if (!request.__isset.tableId) {
        auto tstatus = statusError(TStatusCode::TOYDB_ERR, "tableId is not set");
        setDmlRequest(result, tstatus);
        return;
    }
    if (!request.__isset.rowId) {
        auto tstatus = statusError(TStatusCode::TOYDB_ERR, "rowId is not set");
        setDmlRequest(result, tstatus);
        return;
    }
    if (!request.__isset.rows) {
        auto tstatus = statusError(TStatusCode::TOYDB_ERR, "rows is not set");
        setDmlRequest(result, tstatus);
        return;
    }

    // step 2: get table
    TablePtr table = nullptr;
    Status s = _storage->GetTable(request.tableId, table);
    if (!s.isOk()) {
        auto tstatus = statusError(TStatusCode::TOYKV_ERR, s.MoveErrMsg());
        setDmlRequest(result, tstatus);
        return;
    }

    // step 3: build rows
    auto &rows = request.rows;
    int64_t rowId = request.rowId;

    std::vector<std::string> keys;
    std::vector<std::string> values;
    keys.reserve(rows.size());
    values.reserve(rows.size());

    WriteTask task = _storage->NewTask();
    for (auto &row : rows) {
        keys.push_back(std::move(Storage::GetKey(request.tableId, rowId)));
        std::string value;
        table->BuildRow(row, value); // there is no error in this version
        values.push_back(std::move(value));

        task.AddRow(keys.back(), values.back());
        ++rowId;
    }

    // step 4: write task
    s = _storage->Put(task);
    if (!s.isOk()) {
        auto tstatus = statusError(TStatusCode::TOYKV_ERR, s.MoveErrMsg());
        setDmlRequest(result, tstatus);
        return;
    }

    setDmlRequest(result, statusOK());
}

void ToykvService::Delete(TDmlRes &result, const TDeleteReq &request) {
    if (!request.__isset.tableId) {
        auto tstatus = statusError(TStatusCode::TOYDB_ERR, "tableId is not set");
        setDmlRequest(result, tstatus);
        return;
    }
    if (!request.__isset.rowId) {
        auto tstatus = statusError(TStatusCode::TOYDB_ERR, "rowId is not set");
        setDmlRequest(result, tstatus);
        return;
    }

    Status s = _storage->Delete(request.tableId, request.rowId);
    if (!s.isOk()) {
        auto tstatus = statusError(TStatusCode::TOYKV_ERR, s.MoveErrMsg());
        setDmlRequest(result, tstatus);
        return;
    }

    setDmlRequest(result, statusOK());
}

TStatus ToykvService::statusOK() {
    TStatus tstatus;
    tstatus.__set_code(TStatusCode::OK);
    return tstatus;
}

TStatus ToykvService::statusError(TStatusCode::type code, std::string &&errMsg) {
    TStatus tstatus;
    tstatus.__set_code(code);
    tstatus.__isset.err_msgs = true;
    tstatus.err_msgs.push_back(errMsg);

    return tstatus;
}

void ToykvService::setDmlRequest(TDmlRes &result, const TStatus &tstatus) {
    if (tstatus.code == TStatusCode::OK) {
        result.__set_affectedRow(1);
    } else {
        result.__set_affectedRow(0);
    }

    result.__set_status(tstatus);
}

} // namespace toykv