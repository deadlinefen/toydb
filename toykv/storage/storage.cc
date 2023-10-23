#include "storage.h"

namespace toykv {

storage::storage() : _db(nullptr), _inited(false) {}

storage::~storage() {}

Status storage::Init(const std::string &path) {
    if (_inited) {
        return Status::ToyErr("Init twice");
    }

    leveldb::DB *leveldb = nullptr;
    leveldb::Options opt;
    opt.create_if_missing = true;

    leveldb::Status s = leveldb::DB::Open(opt, path, &leveldb);
    if (!s.ok()) {
        return Status::LeveldbErr(s.ToString());
    }

    _db.reset(leveldb);
    _inited = true;

    return Status::Ok();
}

Status storage::Put(const leveldb::Slice &key, const leveldb::Slice &value) {
    leveldb::Status s = _db->Put(_writeOpt, key, value);
    if (!s.ok()) {
        return Status::LeveldbErr(s.ToString());
    }

    return Status::Ok();
}

Status storage::Delete(const leveldb::Slice &key) {
    leveldb::Status s = _db->Delete(_writeOpt, key);
    if (!s.ok()) {
        return Status::LeveldbErr(s.ToString());
    }

    return Status::Ok();
}

Status storage::Get(const leveldb::Slice &key, std::string *value) {
    leveldb::Status s = _db->Get(_readOpt, key, value);
    if (!s.ok()) {
        return Status::LeveldbErr(s.ToString());
    }

    return Status::Ok();
}
} // namespace toykv