class StringAtom {
 public:
  const char * data() const;
  const char * c_str() const;
  operator std::string ();
  //  bool operator == (std::string) const;
  bool operator == (const std::string ) const;
  
  //bool operator == (const std::string) const;
  bool operator == (StringAtom) const;
  size_t length() const;
  template<class T> void MergeFrom(const T &);

};
bool operator == (const std::string, StringAtom) ;


std::ostream & operator << (std::ostream &, const StringAtom & );

class Value {
 public:
  enum type {
    SCALAR,
    RANGES,
    SET,
    TEXT,
  };

  class Base {};
  class Type_IsValid {
  public:
    Type_IsValid(type);
    operator bool();
  };
  class Scalar : public Base {
  public:
    template <class U> bool operator!=( U ) const;
    template <class U> bool operator==( U ) const;
    template <class U> bool operator<( U ) const;
    bool empty() const;
  };
  class Text : public Base {};
  class Set : public Base {};
  class Ranges : public Base {};
};


class ID {
 public:
  Value::Scalar value() const;
};

class FrameworkID : public ID{
 public:

  //  bool operator ==(const char * ) const;    
};

//bool operator ==(const FrameworkID , const FrameworkID );  

std::ostream & operator << (std::ostream &,const FrameworkID );


class OfferID : public ID{
 public:

};

std::ostream & operator << (std::ostream &,const OfferID );

class Offer {
 public:
  OfferID id() const ;
  StringAtom slave_id() const;
};



class ExecutorID : public ID{
 public:
};

class Resource {
 public:
  StringAtom name() const;
  Value::type type() const;
  Value::Scalar scalar() const;
  Value::Ranges ranges() const;
  Value::Set set() const;

  template <class U> bool operator!=( U & ) const;

};


class MasterInfo{
 public:
  const char * DebugString() const;
  StringAtom id() const;
  StringAtom ip() const;
  StringAtom pid() const;
  StringAtom hostname() const;
  StringAtom port() const;
  bool has_pid() const;
  bool has_hostname() const;
};

class SlaveID : public ID{
 public:

};

class Status { 
 public:
  StringAtom state() const;
  StringAtom task_id() const;
  const FrameworkID & framework_id() const;
};

class TaskStatus : public Status {};


class FrameworkInfo{
 public:
  const FrameworkID & id() const;
  StringAtom name() const;
  StringAtom user() const;
  StringAtom * mutable_id() const;
  bool has_id() const;
  template <class T> void MergeFrom(const T &);
};

class Request{};
class Filters{};
class TaskInfo{
 public:
  const char * DebugString() const;
};
class TaskState{};

class EnumValueDescriptor {
 public:
  StringAtom name() const;

}; 

class EnumDescriptor{
 public:
  template <class T> const EnumValueDescriptor  * FindValueByNumber(const T &) const ;
};

EnumDescriptor * TaskState_descriptor();


class TaskID : public ID {
 public:

};

class ContainerID: public ID{
 public:

};

class Credential{
 public:
  const StringAtom &secret() const;
  bool has_secret() const;
  const StringAtom &principal() const;
};
class Message {
 public:
  template <class T> void set_data(T, int len);
};
class AuthenticateMessage : public Message {
 public:
  template <class T> void set_pid(T);
  
};

class AuthenticationMechanismsMessage : public Message {
 public:
  static int mechanisms();
};

class AuthenticationStepMessage : public Message {
 public:
  int data();
};

class AuthenticationCompletedMessage : public Message {
};

class AuthenticationFailedMessage : public Message {
};

class AuthenticationStartMessage : public Message {
 public:
  template <class T> void set_mechanism(T);


};

class AuthenticationErrorMessage : public Message {
 public:
  static void error();
};




class Bytes {};
class Attribute{
 public:
  StringAtom name() const;
  bool has_name() const;

  Value::type type() const;
  bool has_type() const;

  Value::Scalar scalar() const;
  bool has_scalar() const;

  Value::Ranges ranges() const;
  bool has_ranges() const;

  Value::Text text() const;
  bool has_text() const;

  Value::Set set() const;
  bool has_set() const;
};
class Duration {};

class Variable{
 public:
  StringAtom name() const;
  StringAtom value() const;
};

class Variables{
 public:
  int size() const;
  const Variable &  Get(int) const;
};

class Environment {
 public:
  Variables variables() const;
};

template<class T>
class Collection{
 public:
  int size() const;
  const T &  Get(int) const;
};

class CommandInfo {
 public:
  class URI{
  public:
    StringAtom executable() const;
    StringAtom value() const;
    bool has_executable() const;    
  };
  Collection<URI> uris() const;
  bool has_environment() const;
  Environment environment() const;
  StringAtom value() const;
};


class StatusUpdate {
 public:
  const TaskStatus  & status() const;
  StringAtom uuid() const;
  const FrameworkID & framework_id() const;
  
};

class StatusUpdateRecord {
 public:
  class Type {};
  static EnumDescriptor * Type_descriptor();
};

class Action {
 public:
  class Type {};
  static const char * Type_Name(Type);
};

class Metadata {
 public:
  class Status {};
  static const char * Status_Name(Status);
};
class ACL_vector{};
class Error {
 public:
  Error(const char *);
  //operator Try<URL>();
};

#include <stout/flags.hpp>
#include <process/process.hpp>
#include <mesos/resources.hpp>

class ExecutorInfo{
 public:
  const char * DebugString() const;
  mesos::Resources resources() const;
  const FrameworkID & framework_id() const;
  StringAtom executor_id() const;
  StringAtom name() const;
  StringAtom data() const;
  StringAtom source() const;
  StringAtom command() const;
  bool has_name() const;
  bool has_data() const;
  bool has_source() const;
  bool has_framework_id() const;
};

#include "common/attributes.hpp"

class SlaveInfo{
public:
const char * DebugString() const;
StringAtom hostname() const;
StringAtom id() const;
StringAtom checkpoint() const;
mesos::Resources resources() const;
bool has_id() const;
bool has_checkpoint() const;
//Collection<Attribute> attributes() const;
mesos::internal::Attributes attributes() const;
};

class Task {
 public:
  StringAtom name() const;
  StringAtom task_id() const;
  const FrameworkID & framework_id() const;
  StringAtom slave_id() const;
  bool has_executor_id() const;
  StringAtom executor_id() const;
  StringAtom state() const;
  mesos::Resources resources() const;
};

class UUID {
public:
template <class T> static UUID fromBytes(T);
};



std::ostream & operator << (std::ostream &, const UUID & );

template <class T> class Result {};


class FrameworkRegisteredMessage{
 public:
  const FrameworkID & framework_id() const;
  MasterInfo master_info() const;
};
class ResourceOffersMessage{
 public:
  Collection<Offer> offers();
  Collection<StringAtom> pids();
};
class StatusUpdateMessage{ 
 public:
  const StatusUpdate & update();
  StringAtom pid() const;
};
class LostSlaveMessage{ 
 public:
  StringAtom slave_id() const;
};
class ExecutorToFrameworkMessage{ 
 public:
  StringAtom slave_id() const;
  const FrameworkID & framework_id() const;
  StringAtom executor_id() const;
  const std::string& data() const;
};
class FrameworkErrorMessage{ public:
  const std::string& message() const;
};
class FrameworkReregisteredMessage{
 public:
  const FrameworkID & framework_id() const;
  MasterInfo master_info() const;
};
class RescindResourceOfferMessage {
 public:
  StringAtom offer_id() const;
};

class RegisterFrameworkMessage {
 public:
  FrameworkInfo * mutable_framework();
};

class ReregisterFrameworkMessage {
 public:
  FrameworkInfo * mutable_framework();
  void set_failover(int);
};

class StatusUpdateAcknowledgementMessage {};
class UnregisterFrameworkMessage {};
class DeactivateFrameworkMessage{};
class KillTaskMessage{};
