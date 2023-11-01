/**
 * Autogenerated by Thrift Compiler (0.16.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Ddl_TYPES_H
#define Ddl_TYPES_H

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

class TCreateTableReq;

class TDdlRes;

typedef struct _TCreateTableReq__isset {
  _TCreateTableReq__isset() : tableMeta(false) {}
  bool tableMeta :1;
} _TCreateTableReq__isset;

class TCreateTableReq : public virtual ::apache::thrift::TBase {
 public:

  TCreateTableReq(const TCreateTableReq&);
  TCreateTableReq& operator=(const TCreateTableReq&);
  TCreateTableReq() noexcept
                  : tableMeta() {
  }

  virtual ~TCreateTableReq() noexcept;
  std::string tableMeta;

  _TCreateTableReq__isset __isset;

  void __set_tableMeta(const std::string& val);

  bool operator == (const TCreateTableReq & rhs) const
  {
    if (__isset.tableMeta != rhs.__isset.tableMeta)
      return false;
    else if (__isset.tableMeta && !(tableMeta == rhs.tableMeta))
      return false;
    return true;
  }
  bool operator != (const TCreateTableReq &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TCreateTableReq & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

  virtual void printTo(std::ostream& out) const;
};

void swap(TCreateTableReq &a, TCreateTableReq &b);

std::ostream& operator<<(std::ostream& out, const TCreateTableReq& obj);

typedef struct _TDdlRes__isset {
  _TDdlRes__isset() : status(false) {}
  bool status :1;
} _TDdlRes__isset;

class TDdlRes : public virtual ::apache::thrift::TBase {
 public:

  TDdlRes(const TDdlRes&);
  TDdlRes& operator=(const TDdlRes&);
  TDdlRes() noexcept {
  }

  virtual ~TDdlRes() noexcept;
   ::toykv::TStatus status;

  _TDdlRes__isset __isset;

  void __set_status(const  ::toykv::TStatus& val);

  bool operator == (const TDdlRes & rhs) const
  {
    if (!(status == rhs.status))
      return false;
    return true;
  }
  bool operator != (const TDdlRes &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDdlRes & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

  virtual void printTo(std::ostream& out) const;
};

void swap(TDdlRes &a, TDdlRes &b);

std::ostream& operator<<(std::ostream& out, const TDdlRes& obj);

} // namespace

#endif
