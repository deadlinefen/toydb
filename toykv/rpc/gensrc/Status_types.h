/**
 * Autogenerated by Thrift Compiler (0.16.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Status_TYPES_H
#define Status_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <memory>


namespace toykv {

struct TStatusCode {
  enum type {
    OK = 0,
    TOYDB_ERR = 1,
    TOYKV_ERR = 2,
    TOYFLASH_ERR = 3,
    LEVELDB_ERR = 4
  };
};

extern const std::map<int, const char*> _TStatusCode_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const TStatusCode::type& val);

std::string to_string(const TStatusCode::type& val);

class TStatus;

typedef struct _TStatus__isset {
  _TStatus__isset() : err_msgs(false) {}
  bool err_msgs :1;
} _TStatus__isset;

class TStatus : public virtual ::apache::thrift::TBase {
 public:

  TStatus(const TStatus&);
  TStatus& operator=(const TStatus&);
  TStatus() noexcept
          : code(static_cast<TStatusCode::type>(0)) {
  }

  virtual ~TStatus() noexcept;
  /**
   * 
   * @see TStatusCode
   */
  TStatusCode::type code;
  std::vector<std::string>  err_msgs;

  _TStatus__isset __isset;

  void __set_code(const TStatusCode::type val);

  void __set_err_msgs(const std::vector<std::string> & val);

  bool operator == (const TStatus & rhs) const
  {
    if (!(code == rhs.code))
      return false;
    if (__isset.err_msgs != rhs.__isset.err_msgs)
      return false;
    else if (__isset.err_msgs && !(err_msgs == rhs.err_msgs))
      return false;
    return true;
  }
  bool operator != (const TStatus &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TStatus & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

  virtual void printTo(std::ostream& out) const;
};

void swap(TStatus &a, TStatus &b);

std::ostream& operator<<(std::ostream& out, const TStatus& obj);

} // namespace

#endif
