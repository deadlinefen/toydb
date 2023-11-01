namespace cpp toykv

include "Dml.thrift"
include "Ddl.thrift"

service ToykvService {
    Dml.TDmlRes Insert(1: Dml.TInsertReq insertReq)
    Dml.TDmlRes Delete(1: Dml.TDeleteReq deleteReq)

    Ddl.TDdlRes CreateTable(1: Ddl.TCreateTableReq createTableReq)
}