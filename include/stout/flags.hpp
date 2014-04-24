#pragma once


class Nothing {};

template <class T> class Try
{
public:
  template <class U> Try(U);
  bool isError() const;
  const char * error() const;
};

namespace flags {
  class FlagsBase {
  protected :
    // void add(T&,const char*,const char*, bool);
    template <class T> void add(T val, const char *, const char *, bool flag=0);
  public:
    Try<Nothing> load(const char *);
  };
}



namespace google {
  class LogSeverity{};
}
