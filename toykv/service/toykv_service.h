#pragma once

#include "rpc/gensrc/ToykvService.h"
#include "storage/storage.h"

namespace toykv {

class ToykvService final : virtual public ToykvServiceIf {
public:
    ToykvService(storagePtr storage) : _storage(storage) {}
    ~ToykvService() = default;

    void Insert(TDmlRes &result, const TInsertReq &request) override;
    void Delete(TDmlRes &result, const TDeleteReq &request) override;

    void CreateTable(TDdlRes &_return, const TCreateTableReq &createTableReq) override;

private:
    inline TStatus statusOK();
    inline TStatus statusError(TStatusCode::type code, std::string &&errMsg);

    inline void setDmlRequest(TDmlRes &result, const TStatus &tstatus);

    storagePtr _storage;
};

} // namespace toykv