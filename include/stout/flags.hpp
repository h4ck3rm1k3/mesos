#pragma once

namespace flags {
  class FlagsBase {
  protected :
    // void add(T&,const char*,const char*, bool);
    template <class T> void add(T val, const char *, const char *, bool flag=0);

  };
}

template <class T> class Try{};


namespace google {
  class LogSeverity{};
}
