#pragma once

#include <leveldb/db.h>
#include <leveldb/slice.h>

#include <memory>

#include "utils/status.h"

namespace toykv {

class storage {
    using dbPtr = std::shared_ptr<leveldb::DB>;

public:
    storage();
    ~storage();

    Status Init(const std::string &path);
    inline Status Put(const leveldb::Slice &key, const leveldb::Slice &value);
    inline Status Delete(const leveldb::Slice &key);
    inline Status Get(const leveldb::Slice &key, std::string *value);

private:
    static constexpr leveldb::WriteOptions _writeOpt;
    static constexpr leveldb::ReadOptions _readOpt;

    dbPtr _db;
    bool _inited;
};

} // namespace toykv