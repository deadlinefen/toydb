#pragma once
#include <leveldb/status.h>

namespace toykv {

class Status {
public:
    Status() noexcept : _code(kOk), _errMsg() {}
    ~Status() {}

    static Status Ok() { return Status(); }
    static Status ToyErr(std::string &&s) { return Status(kToy, std::move(s)); }
    static Status LeveldbErr(std::string &&s) { return Status(kLeveldb, std::move(s)); }

private:
    enum Code { kOk, kToy, kLeveldb };

    Status(Code code) : _code(code), _errMsg() {}
    Status(Code code, std::string &&s) : _code(code), _errMsg(s) {}

    Code _code;
    std::string _errMsg;
};

} // namespace toykv