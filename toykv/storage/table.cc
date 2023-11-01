#include "table.h"

#include "row.h"

namespace toykv {

TablePtr Table::GetTable(const std::string &meta) {
    TablePtr table = std::make_shared<Table>();
    if (!table->_meta.ParseFromString(meta)) {
        return nullptr;
    }

    auto &fields = table->_meta.fields();
    auto &prefixSum = table->_prefixSum;

    int fixedSize = 0;
    bool needAddToPrefix = true;
    for (auto &field : fields) {
        bool needAddToFixedSize = isDynamicLength(field);

        if (needAddToPrefix) {
            prefixSum.push_back(fixedSize);
            needAddToPrefix = needAddToFixedSize;
        }

        if (needAddToFixedSize) {
            fixedSize += field.length();
        }
    }

    table->_fixedSize = fixedSize;

    return table;
}

Status Table::BuildRow(const TRow &row, std::string &rowData) {
    // step 1: get row length
    auto &varcharLength = row.vars;
    // TODO: support null
    int size = _fixedSize;
    for (auto length : varcharLength) {
        size += length;
    }
    size += sizeof(Header);                     // add header length
    size += sizeof(int) * varcharLength.size(); // add varchar meta length
    // TODO: add null meta length
    rowData.resize(size);

    // step 2: set row header
    Header *header = reinterpret_cast<Header *>(rowData.data());
    header->SetVarcharColumnNum(varcharLength.size());
    header->SetNullColumnNum(0); // TODO: set correct null length

    // step 3: set varchar length
    int *rowVarcharLength = header->GetVarcharColumnLength();
    memcpy(rowVarcharLength, varcharLength.data(), sizeof(int) * varcharLength.size());

    // step 4: TODO set null info

    // step 5: copy data
    char *data = header->GetData();
    auto &fields = _meta.fields();
    auto &cols = row.cols;
    assert(_meta.fields().size() == cols.size());
    for (int c = 0; c < fields.size(); ++c) {
        memcpy(data, cols[c].data(), cols[c].size());
        if (isDynamicLength(fields[c])) {
            data += cols[c].size();
        } else {
            data += fields[c].length();
        }
    }

    return Status::Ok();
}

} // namespace toykv