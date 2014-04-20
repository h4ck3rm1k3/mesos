#pragma once

class Event {};

namespace process {
  
  class UPID{
  public:
     operator int() const;
  };
  class Once{
  public:
    bool once();
    void done();
  };
  class ID{
  public:
    static ID generate(const char * name);

  };

  template <class T> class Future {
  public:
    void onDiscard(Event x);
  };

  template <class T> class Promise {
  public:
    void fail(const char *);
    void fail(std::string );
    void set(bool );
    Future<T> future();
  };

};


class ProcessBase {
public:
  void send(int pid, Message & m);
  void reply(Message & m);
};

class Self {
public:
  void discarded();
};



template <class T> class ProtobufProcess : public ProcessBase
{
public:
  ProtobufProcess(process::ID);
  Self self();
  template <class U> Event defer(Self,U);
  template <class U, class V, class X> void install(V x, X y);
  template <class U, class V> void install(V x);
  
};
namespace process {
  template <class T> void spawn(T);
  //  template <class T, class U, class V,class X> X dispatch(T,U,V);
  template <class T, class U, class V>  Future<bool> dispatch(T,U,V);
  template <class T> void terminate(T);
  template <class T> void wait(T);
};
