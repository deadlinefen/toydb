#pragma once

#include <memory>
#include <vector>

#include "row.h"
#include "rpc/gensrc/TableMeta.pb.h"

namespace toykv {

class Table;
using TablePtr = std::shared_ptr<Table>;

class Table {
public:
    static TablePtr GetTable(const std::string &meta);
    Status BuildRow(const TRow &row, std::string &rowData);

private:
    inline static bool isDynamicLength(const PFieldMeta &meta) {
        return meta.nullable() || meta.type() == PFieldMeta_PFieldType_VARCHAR;
    }

    PTableMeta _meta;
    std::vector<int> _prefixSum;
    int _fixedSize;
};

} // namespace toykv