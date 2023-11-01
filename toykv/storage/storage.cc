#include "storage.h"

#include <fmt/format.h>

#include "utils/compiler_util.h"

namespace toykv {

Storage::Storage() : _db(nullptr), _inited(false) {}

Storage::~Storage() {}

Status Storage::Init(const std::string &path) {
    if (UNLIKELY(_inited)) {
        return Status::ToyErr("Init twice");
    }

    rocksdb::Options opt;
    opt.create_if_missing = true;
    opt.create_missing_column_families = true;

    std::vector<rocksdb::ColumnFamilyDescriptor> descriptors;
    descriptors.emplace_back("META", opt);
    descriptors.emplace_back("DATA", opt);

    rocksdb::DB *rocksdb = nullptr;
    rocksdb::Status s = rocksdb::DB::Open(opt, path, descriptors, &_columnFamliy, &rocksdb);
    if (!s.ok()) {
        return Status::RocksdbErr(s.ToString());
    }

    _db.reset(rocksdb);
    _inited = true;

    return Status::Ok();
}

Status Storage::CreateTable(const int64_t tableId, const std::string_view &meta) {
    std::string key = GetTableKey(tableId);
    rocksdb::WriteOptions writeOpt;
    rocksdb::Status s = _db->Put(writeOpt, _columnFamliy[kMeta], key, meta);
    if (!s.ok()) {
        return Status::RocksdbErr(s.ToString());
    }

    return Status::Ok();
}

Status Storage::GetTable(const int64_t tableId, TablePtr &table) {
    std::string meta;
    rocksdb::Status s = getTableMeta(tableId, &meta);
    if (!s.ok()) {
        return Status::RocksdbErr(s.ToString());
    }

    TablePtr table = Table::GetTable(meta);
    if (table == nullptr) {
        return Status::ToyErr(fmt::format("get table %d meta failed", tableId));
    }

    return Status::Ok();
}

Status Storage::Put(const int64_t tableId, const int64_t rowId, const std::string_view &value) {
    if (UNLIKELY(!_inited)) {
        return Status::ToyErr("Not inited!");
    }

    std::string key = GetKey(tableId, rowId);
    rocksdb::WriteOptions writeOpt;
    rocksdb::Status s = _db->Put(writeOpt, _columnFamliy[kData], key, value);
    if (!s.ok()) {
        return Status::RocksdbErr(s.ToString());
    }

    return Status::Ok();
}

Status Storage::Put(WriteTask &task) {
    if (UNLIKELY(!_inited)) {
        return Status::ToyErr("Not inited!");
    }

    rocksdb::WriteOptions writeOpt;
    rocksdb::Status s = _db->Write(writeOpt, task.getWriteBatch());
    if (!s.ok()) {
        return Status::RocksdbErr(s.ToString());
    }

    return Status::Ok();
}

inline Status Storage::Delete(const int64_t tableId, const int64_t rowId) {
    return Delete(GetKey(tableId, rowId));
}

Status Storage::Delete(const std::string_view &key) {
    if (UNLIKELY(!_inited)) {
        return Status::ToyErr("Not inited!");
    }

    rocksdb::WriteOptions writeOpt;
    rocksdb::Status s = _db->Delete(writeOpt, _columnFamliy[kData], key);
    if (!s.ok()) {
        return Status::RocksdbErr(s.ToString());
    }

    return Status::Ok();
}

inline rocksdb::Status Storage::getTableMeta(const int64_t tableId, std::string *meta) {
    rocksdb::ReadOptions readOpt;
    return _db->Get(readOpt, GetTableKey(tableId), meta);
}

} // namespace toykv