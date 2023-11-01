#include "row.h"

namespace toykv {

template <>
bool ColumnFilter<std::string_view>::IsValid(const void *row,
                                             std::function<bool(std::string_view)> filter) {
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

    assert(_dynamicIdxNum < header->GetVarcharColumnNum());

    int64_t length = _length;
    if (length < 0) {
        length = varcharLength[_dynamicIdxNum];
    }

    return filter(std::string_view(data, length));
}

} // namespace toykv
