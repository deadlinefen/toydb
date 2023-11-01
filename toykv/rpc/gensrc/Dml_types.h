/**
 * Autogenerated by Thrift Compiler (0.16.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Dml_TYPES_H
#define Dml_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <memory>
#include "Status_types.h"


namespace toykv {

class TRow;

class TInsertReq;

class TDeleteReq;

class TDmlRes;

typedef struct _TRow__isset {
  _TRow__isset() : vars(false), nulls(false), cols(false) {}
  bool vars :1;
  bool nulls :1;
  bool cols :1;
} _TRow__isset;

class TRow : public virtual ::apache::thrift::TBase {
 public:

  TRow(const TRow&);
  TRow& operator=(const TRow&);
  TRow() noexcept {
  }

  virtual ~TRow() noexcept;
  std::vector<int32_t>  vars;
  std::vector<int32_t>  nulls;
  std::vector<std::string>  cols;

  _TRow__isset __isset;

  void __set_vars(const std::vector<int32_t> & val);

  void __set_nulls(const std::vector<int32_t> & val);

  void __set_cols(const std::vector<std::string> & val);

  bool operator == (const TRow & rhs) const
  {
    if (__isset.vars != rhs.__isset.vars)
      return false;
    else if (__isset.vars && !(vars == rhs.vars))
      return false;
    if (__isset.nulls != rhs.__isset.nulls)
      return false;
    else if (__isset.nulls && !(nulls == rhs.nulls))
      return false;
    if (__isset.cols != rhs.__isset.cols)
      return false;
    else if (__isset.cols && !(cols == rhs.cols))
      return false;
    return true;
  }
  bool operator != (const TRow &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TRow & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

  virtual void printTo(std::ostream& out) const;
};

void swap(TRow &a, TRow &b);

std::ostream& operator<<(std::ostream& out, const TRow& obj);

typedef struct _TInsertReq__isset {
  _TInsertReq__isset() : tableId(false), rowId(false), rows(false) {}
  bool tableId :1;
  bool rowId :1;
  bool rows :1;
} _TInsertReq__isset;

class TInsertReq : public virtual ::apache::thrift::TBase {
 public:

  TInsertReq(const TInsertReq&);
  TInsertReq& operator=(const TInsertReq&);
  TInsertReq() noexcept
             : tableId(0),
               rowId(0) {
  }

  virtual ~TInsertReq() noexcept;
  int64_t tableId;
  int64_t rowId;
  std::vector<TRow>  rows;

  _TInsertReq__isset __isset;

  void __set_tableId(const int64_t val);

  void __set_rowId(const int64_t val);

  void __set_rows(const std::vector<TRow> & val);

  bool operator == (const TInsertReq & rhs) const
  {
    if (__isset.tableId != rhs.__isset.tableId)
      return false;
    else if (__isset.tableId && !(tableId == rhs.tableId))
      return false;
    if (__isset.rowId != rhs.__isset.rowId)
      return false;
    else if (__isset.rowId && !(rowId == rhs.rowId))
      return false;
    if (__isset.rows != rhs.__isset.rows)
      return false;
    else if (__isset.rows && !(rows == rhs.rows))
      return false;
    return true;
  }
  bool operator != (const TInsertReq &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TInsertReq & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

  virtual void printTo(std::ostream& out) const;
};

void swap(TInsertReq &a, TInsertReq &b);

std::ostream& operator<<(std::ostream& out, const TInsertReq& obj);

typedef struct _TDeleteReq__isset {
  _TDeleteReq__isset() : tableId(false), rowId(false) {}
  bool tableId :1;
  bool rowId :1;
} _TDeleteReq__isset;

class TDeleteReq : public virtual ::apache::thrift::TBase {
 public:

  TDeleteReq(const TDeleteReq&) noexcept;
  TDeleteReq& operator=(const TDeleteReq&) noexcept;
  TDeleteReq() noexcept
             : tableId(0),
               rowId(0) {
  }

  virtual ~TDeleteReq() noexcept;
  int64_t tableId;
  int64_t rowId;

  _TDeleteReq__isset __isset;

  void __set_tableId(const int64_t val);

  void __set_rowId(const int64_t val);

  bool operator == (const TDeleteReq & rhs) const
  {
    if (__isset.tableId != rhs.__isset.tableId)
      return false;
    else if (__isset.tableId && !(tableId == rhs.tableId))
      return false;
    if (__isset.rowId != rhs.__isset.rowId)
      return false;
    else if (__isset.rowId && !(rowId == rhs.rowId))
      return false;
    return true;
  }
  bool operator != (const TDeleteReq &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDeleteReq & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

  virtual void printTo(std::ostream& out) const;
};

void swap(TDeleteReq &a, TDeleteReq &b);

std::ostream& operator<<(std::ostream& out, const TDeleteReq& obj);

typedef struct _TDmlRes__isset {
  _TDmlRes__isset() : status(false), affectedRow(false) {}
  bool status :1;
  bool affectedRow :1;
} _TDmlRes__isset;

class TDmlRes : public virtual ::apache::thrift::TBase {
 public:

  TDmlRes(const TDmlRes&);
  TDmlRes& operator=(const TDmlRes&);
  TDmlRes() noexcept
          : affectedRow(0) {
  }

  virtual ~TDmlRes() noexcept;
   ::toykv::TStatus status;
  int64_t affectedRow;

  _TDmlRes__isset __isset;

  void __set_status(const  ::toykv::TStatus& val);

  void __set_affectedRow(const int64_t val);

  bool operator == (const TDmlRes & rhs) const
  {
    if (__isset.status != rhs.__isset.status)
      return false;
    else if (__isset.status && !(status == rhs.status))
      return false;
    if (__isset.affectedRow != rhs.__isset.affectedRow)
      return false;
    else if (__isset.affectedRow && !(affectedRow == rhs.affectedRow))
      return false;
    return true;
  }
  bool operator != (const TDmlRes &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDmlRes & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

  virtual void printTo(std::ostream& out) const;
};

void swap(TDmlRes &a, TDmlRes &b);

std::ostream& operator<<(std::ostream& out, const TDmlRes& obj);

} // namespace

#endif
