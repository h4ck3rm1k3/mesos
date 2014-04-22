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
    UPID();
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
    bool discard();
    bool isFailed() const;
    bool isReady() const;
    bool onAny(Event x);
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
  template <class T,class U> void send(T pid, U & m);
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

  template <class U, class V, class X, class Y> void delay(U u, V v, X x, Y y);
  template <class U, class V, class X> void delay(U u, V v, X x);

  //  template <class T, class U, class V,class X> X dispatch(T,U,V);

  
};

class SavedOffers {
public:
  template <class T> void erase(T);
};

class FlagsVerbose {
public:
  bool operator >= (int);
};

namespace process {
  template <class U> void wait(U);
  template <class U> void terminate(U);
  template <class U> void spawn(U);
  template <class U, class V, class X> process::Future<bool> dispatch(U,V,X);
  template <class U, class V, class X, class Y> process::Future<bool> dispatch(U,V,X,Y);
  template <class U, class V> process::Future<bool> dispatch(U,V);
  SavedOffers savedOffers ;

  class Timer {};
  class Seconds {
    Seconds(int);
  };

  class Stopwatch {
  public:
    void start();
    long elapsed();
  };

  FlagsVerbose FLAGS_v; // the verbose flag
  
};




class Seconds {
public:
  Seconds(int);
};

