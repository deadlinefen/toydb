namespace cpp toykv

include "Status.thrift"

struct TCreateTableReq {
    1: optional string tableMeta
}

struct TDdlRes {
    1: Status.TStatus status
}