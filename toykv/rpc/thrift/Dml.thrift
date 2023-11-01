namespace cpp toykv

include "Status.thrift"

struct TRow {
    1: optional list<i32> vars
    2: optional list<i32> nulls
    3: optional list<string> cols
}

struct TInsertReq {
    1: optional i64 tableId
    2: optional i64 rowId
    3: optional list<TRow> rows
}

struct TDeleteReq {
    1: optional i64 tableId
    2: optional i64 rowId
}

struct TDmlRes {
    1: optional Status.TStatus status
    2: optional i64 affectedRow
}