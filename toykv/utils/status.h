#pragma once
#include <leveldb/status.h>

namespace toykv {

class Status {
public:
    enum Code { kOk, kToy, kRocksdb };

    Status() noexcept : _code(kOk), _errMsg() {}
    ~Status() {}

    static Status Ok() { return Status(); }
    static Status ToyErr(std::string &&s) { return Status(kToy, std::move(s)); }
    static Status RocksdbErr(std::string &&s) { return Status(kRocksdb, std::move(s)); }

    inline bool isOk() { return _code == kOk; }
    inline Code GetCode() const { return _code; }

    inline std::string &&MoveErrMsg() { return std::move(_errMsg); }
    inline std::string GetErrMsg() const { return _errMsg; };

private:
    Status(Code code) : _code(code), _errMsg() {}
    Status(Code code, std::string &&s) : _code(code), _errMsg(s) {}

    Code _code;
    std::string _errMsg;
};

} // namespace toykv