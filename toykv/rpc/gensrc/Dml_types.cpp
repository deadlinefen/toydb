/**
 * Autogenerated by Thrift Compiler (0.16.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "Dml_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace toykv {


TRow::~TRow() noexcept {
}


void TRow::__set_vars(const std::vector<int32_t> & val) {
  this->vars = val;
__isset.vars = true;
}

void TRow::__set_nulls(const std::vector<int32_t> & val) {
  this->nulls = val;
__isset.nulls = true;
}

void TRow::__set_cols(const std::vector<std::string> & val) {
  this->cols = val;
__isset.cols = true;
}
std::ostream& operator<<(std::ostream& out, const TRow& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t TRow::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->vars.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _etype3;
            xfer += iprot->readListBegin(_etype3, _size0);
            this->vars.resize(_size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              xfer += iprot->readI32(this->vars[_i4]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.vars = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->nulls.clear();
            uint32_t _size5;
            ::apache::thrift::protocol::TType _etype8;
            xfer += iprot->readListBegin(_etype8, _size5);
            this->nulls.resize(_size5);
            uint32_t _i9;
            for (_i9 = 0; _i9 < _size5; ++_i9)
            {
              xfer += iprot->readI32(this->nulls[_i9]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.nulls = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->cols.clear();
            uint32_t _size10;
            ::apache::thrift::protocol::TType _etype13;
            xfer += iprot->readListBegin(_etype13, _size10);
            this->cols.resize(_size10);
            uint32_t _i14;
            for (_i14 = 0; _i14 < _size10; ++_i14)
            {
              xfer += iprot->readString(this->cols[_i14]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.cols = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t TRow::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TRow");

  if (this->__isset.vars) {
    xfer += oprot->writeFieldBegin("vars", ::apache::thrift::protocol::T_LIST, 1);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->vars.size()));
      std::vector<int32_t> ::const_iterator _iter15;
      for (_iter15 = this->vars.begin(); _iter15 != this->vars.end(); ++_iter15)
      {
        xfer += oprot->writeI32((*_iter15));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.nulls) {
    xfer += oprot->writeFieldBegin("nulls", ::apache::thrift::protocol::T_LIST, 2);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->nulls.size()));
      std::vector<int32_t> ::const_iterator _iter16;
      for (_iter16 = this->nulls.begin(); _iter16 != this->nulls.end(); ++_iter16)
      {
        xfer += oprot->writeI32((*_iter16));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.cols) {
    xfer += oprot->writeFieldBegin("cols", ::apache::thrift::protocol::T_LIST, 3);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->cols.size()));
      std::vector<std::string> ::const_iterator _iter17;
      for (_iter17 = this->cols.begin(); _iter17 != this->cols.end(); ++_iter17)
      {
        xfer += oprot->writeString((*_iter17));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TRow &a, TRow &b) {
  using ::std::swap;
  swap(a.vars, b.vars);
  swap(a.nulls, b.nulls);
  swap(a.cols, b.cols);
  swap(a.__isset, b.__isset);
}

TRow::TRow(const TRow& other18) {
  vars = other18.vars;
  nulls = other18.nulls;
  cols = other18.cols;
  __isset = other18.__isset;
}
TRow& TRow::operator=(const TRow& other19) {
  vars = other19.vars;
  nulls = other19.nulls;
  cols = other19.cols;
  __isset = other19.__isset;
  return *this;
}
void TRow::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TRow(";
  out << "vars="; (__isset.vars ? (out << to_string(vars)) : (out << "<null>"));
  out << ", " << "nulls="; (__isset.nulls ? (out << to_string(nulls)) : (out << "<null>"));
  out << ", " << "cols="; (__isset.cols ? (out << to_string(cols)) : (out << "<null>"));
  out << ")";
}


TInsertReq::~TInsertReq() noexcept {
}


void TInsertReq::__set_tableId(const int64_t val) {
  this->tableId = val;
__isset.tableId = true;
}

void TInsertReq::__set_rowId(const int64_t val) {
  this->rowId = val;
__isset.rowId = true;
}

void TInsertReq::__set_rows(const std::vector<TRow> & val) {
  this->rows = val;
__isset.rows = true;
}
std::ostream& operator<<(std::ostream& out, const TInsertReq& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t TInsertReq::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->tableId);
          this->__isset.tableId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->rowId);
          this->__isset.rowId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->rows.clear();
            uint32_t _size20;
            ::apache::thrift::protocol::TType _etype23;
            xfer += iprot->readListBegin(_etype23, _size20);
            this->rows.resize(_size20);
            uint32_t _i24;
            for (_i24 = 0; _i24 < _size20; ++_i24)
            {
              xfer += this->rows[_i24].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.rows = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t TInsertReq::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TInsertReq");

  if (this->__isset.tableId) {
    xfer += oprot->writeFieldBegin("tableId", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64(this->tableId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.rowId) {
    xfer += oprot->writeFieldBegin("rowId", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->rowId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.rows) {
    xfer += oprot->writeFieldBegin("rows", ::apache::thrift::protocol::T_LIST, 3);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->rows.size()));
      std::vector<TRow> ::const_iterator _iter25;
      for (_iter25 = this->rows.begin(); _iter25 != this->rows.end(); ++_iter25)
      {
        xfer += (*_iter25).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TInsertReq &a, TInsertReq &b) {
  using ::std::swap;
  swap(a.tableId, b.tableId);
  swap(a.rowId, b.rowId);
  swap(a.rows, b.rows);
  swap(a.__isset, b.__isset);
}

TInsertReq::TInsertReq(const TInsertReq& other26) {
  tableId = other26.tableId;
  rowId = other26.rowId;
  rows = other26.rows;
  __isset = other26.__isset;
}
TInsertReq& TInsertReq::operator=(const TInsertReq& other27) {
  tableId = other27.tableId;
  rowId = other27.rowId;
  rows = other27.rows;
  __isset = other27.__isset;
  return *this;
}
void TInsertReq::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TInsertReq(";
  out << "tableId="; (__isset.tableId ? (out << to_string(tableId)) : (out << "<null>"));
  out << ", " << "rowId="; (__isset.rowId ? (out << to_string(rowId)) : (out << "<null>"));
  out << ", " << "rows="; (__isset.rows ? (out << to_string(rows)) : (out << "<null>"));
  out << ")";
}


TDeleteReq::~TDeleteReq() noexcept {
}


void TDeleteReq::__set_tableId(const int64_t val) {
  this->tableId = val;
__isset.tableId = true;
}

void TDeleteReq::__set_rowId(const int64_t val) {
  this->rowId = val;
__isset.rowId = true;
}
std::ostream& operator<<(std::ostream& out, const TDeleteReq& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t TDeleteReq::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->tableId);
          this->__isset.tableId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->rowId);
          this->__isset.rowId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t TDeleteReq::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TDeleteReq");

  if (this->__isset.tableId) {
    xfer += oprot->writeFieldBegin("tableId", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64(this->tableId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.rowId) {
    xfer += oprot->writeFieldBegin("rowId", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->rowId);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TDeleteReq &a, TDeleteReq &b) {
  using ::std::swap;
  swap(a.tableId, b.tableId);
  swap(a.rowId, b.rowId);
  swap(a.__isset, b.__isset);
}

TDeleteReq::TDeleteReq(const TDeleteReq& other28) noexcept {
  tableId = other28.tableId;
  rowId = other28.rowId;
  __isset = other28.__isset;
}
TDeleteReq& TDeleteReq::operator=(const TDeleteReq& other29) noexcept {
  tableId = other29.tableId;
  rowId = other29.rowId;
  __isset = other29.__isset;
  return *this;
}
void TDeleteReq::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TDeleteReq(";
  out << "tableId="; (__isset.tableId ? (out << to_string(tableId)) : (out << "<null>"));
  out << ", " << "rowId="; (__isset.rowId ? (out << to_string(rowId)) : (out << "<null>"));
  out << ")";
}


TDmlRes::~TDmlRes() noexcept {
}


void TDmlRes::__set_status(const  ::toykv::TStatus& val) {
  this->status = val;
__isset.status = true;
}

void TDmlRes::__set_affectedRow(const int64_t val) {
  this->affectedRow = val;
__isset.affectedRow = true;
}
std::ostream& operator<<(std::ostream& out, const TDmlRes& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t TDmlRes::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->status.read(iprot);
          this->__isset.status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->affectedRow);
          this->__isset.affectedRow = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t TDmlRes::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TDmlRes");

  if (this->__isset.status) {
    xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->status.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.affectedRow) {
    xfer += oprot->writeFieldBegin("affectedRow", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->affectedRow);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TDmlRes &a, TDmlRes &b) {
  using ::std::swap;
  swap(a.status, b.status);
  swap(a.affectedRow, b.affectedRow);
  swap(a.__isset, b.__isset);
}

TDmlRes::TDmlRes(const TDmlRes& other30) {
  status = other30.status;
  affectedRow = other30.affectedRow;
  __isset = other30.__isset;
}
TDmlRes& TDmlRes::operator=(const TDmlRes& other31) {
  status = other31.status;
  affectedRow = other31.affectedRow;
  __isset = other31.__isset;
  return *this;
}
void TDmlRes::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TDmlRes(";
  out << "status="; (__isset.status ? (out << to_string(status)) : (out << "<null>"));
  out << ", " << "affectedRow="; (__isset.affectedRow ? (out << to_string(affectedRow)) : (out << "<null>"));
  out << ")";
}

} // namespace
