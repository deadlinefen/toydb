#pragma once

#include <fmt/format.h>
#include <rocksdb/db.h>

#include <memory>

#include "table.h"
#include "utils/status.h"

namespace toykv {

using dbPtr = std::shared_ptr<rocksdb::DB>;

class WriteTask {
public:
    WriteTask(rocksdb::ColumnFamilyHandle *handle) : _handle(handle) {}

    inline Status AddRow(const std::string_view &key, const std::string_view &value) {
        rocksdb::Status s = _batch.Put(_handle, key, value);
        if (!s.ok()) {
            return Status::RocksdbErr(fmt::format("add key %s failed", key));
        }
        return Status::Ok();
    }

private:
    friend class Storage;
    inline rocksdb::WriteBatch *getWriteBatch() { return &_batch; }

    rocksdb::ColumnFamilyHandle *_handle;
    rocksdb::WriteBatch _batch;
};

class Storage {
public:
    Storage();
    ~Storage();

    Status Init(const std::string &path);

    Status CreateTable(const int64_t tableId, const std::string_view &meta);
    Status GetTable(const int64_t tableId, TablePtr &table);

    Status Put(const int64_t tableId, const int64_t rowId, const std::string_view &value);
    Status Put(WriteTask &transaction);

    Status Delete(const int64_t tableId, const int64_t row);
    Status Delete(const std::string_view &key);

    inline WriteTask NewTask() { return {_columnFamliy[kData]}; }

    inline static std::string GetKey(const int64_t tableId, const int64_t rowId) {
        return fmt::format("t{}_r{}", tableId, rowId);
    }

    inline static std::string GetTableKey(const int64_t tableId) {
        return fmt::format("t{}", tableId);
    }

private:
    rocksdb::Status getTableMeta(const int64_t tableId, std::string *meta);

    static constexpr int kMeta = 0;
    static constexpr int kData = 1;

    dbPtr _db;
    std::vector<rocksdb::ColumnFamilyHandle *> _columnFamliy;
    bool _inited;
};
using storagePtr = std::shared_ptr<Storage>;

} // namespace toykv