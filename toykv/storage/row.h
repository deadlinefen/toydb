#pragma once

#include <fmt/format.h>

#include <cassert>
#include <string_view>
#include <vector>

#include "rpc/gensrc/Dml_types.h"
#include "utils/compiler_util.h"
#include "utils/status.h"

namespace toykv {

class Header final {
public:
    inline int GetVarcharColumnNum() { return _varcharColumnNum; }
    inline void SetVarcharColumnNum(int num) { _varcharColumnNum = num; }
    inline int GetNullColumnNum() { return _nullColumnNum; }
    inline void SetNullColumnNum(int num) { _nullColumnNum = num; }

    inline int *GetVarcharColumnLength() { return _varcharColumnLength; }
    inline char *GetNullColumnIndex() {
        return reinterpret_cast<char *>(_varcharColumnLength + _varcharColumnNum);
    }
    inline char *GetData() { return GetNullColumnIndex() + _nullColumnNum; }

private:
    int _varcharColumnNum;
    int _nullColumnNum;
    int _varcharColumnLength[0];
};

template <typename T>
class ColumnFilter {
public:
    bool IsValid(const void *row, std::function<bool(T)> filter) {
        if (UNLIKELY(row == nullptr)) {
            return false;
        }

        // TODO: support null
        auto header = static_cast<const Header *>(row);
        const int64_t *varcharLength = header->GetVarcharColumnLength();
        const char *data = header->GetData();

        data += _fixedLength;
        for (int i = 0; i < _dynamicIdxNum; ++i) {
            data += varcharLength[i];
        }

        return filter(*static_cast<T *>(data));
    }

private:
    ColumnFilter(int fixedLength, int dynamicIdxNum, int length = -1)
            : _fixedLength(fixedLength), _dynamicIdxNum(dynamicIdxNum), _length(length) {
        static_assert(typeCheck(), "unsupport type");
    }

    bool typeCheck() {
        return typeid(T) == typeid(int64_t) || typeid(T) == typeid(double) ||
               typeid(T) == typeid(std::string_view);
    }
    int _fixedLength;
    int _dynamicIdxNum;
    int _length;
};

} // namespace toykv