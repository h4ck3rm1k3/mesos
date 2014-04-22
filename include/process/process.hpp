#pragma once

class Event {};

namespace lambda {
  void _1();
}
namespace process {
  template <class T> class PID{};
  template <class T> class Owned{};

  class UPID{
  public:
    template <class T> UPID(T);
    //operator int() const;
    operator const char * () const;
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
    bool isDiscarded() const;
    void discard();
    bool isFailed() const;
    void onAny(Event x);
    T get() const;
    std::string failure() const;
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
  template <class T> void send(T pid, Message & m);
  void reply(Message & m);
};




template <class T> class Process : public ProcessBase
{
};

template <class T> class ProtobufProcess : public ProcessBase
{
public:
  ProtobufProcess();
  ProtobufProcess(process::ID);
  ProtobufProcess self();
  void link(process::UPID);
  template <class U, class S> Event defer(S,U);
  template <class U, class V, class S> Event defer(S ,U, V);
  template <class U, class V, class X> void install(V x, X y);
  template <class U, class V, class X, class Y> void install(V v, X x, Y y);
  template <class U, class V, class X, class Y, class Z> void install(V v, X x, Y y, Z z);
  template <class U, class V, class X, class Y, class Z, class AA> void install(V v, X x, Y y, Z z, AA a);
  template <class U, class V> void install(V x);

  
  
};
namespace process {
  template <class T> void spawn(T);
  //  template <class T, class U, class V,class X> X dispatch(T,U,V);
  template <class T, class U, class V>  Future<bool> dispatch(T,U,V);
  template <class T> void terminate(T);
  template <class T> void wait(T);

class Timer {};
class Seconds {
  Seconds(int);
};

};

class Stopwatch {
public:
  void start();
  long elapsed();
};




