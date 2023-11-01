namespace cpp toykv

enum TStatusCode {
    OK = 0,
    TOYDB_ERR = 1,
    TOYKV_ERR = 2,
    TOYFLASH_ERR = 3,
    LEVELDB_ERR = 4,
}

struct TStatus {
    1: required TStatusCode code
    2: optional list<string> err_msgs
}