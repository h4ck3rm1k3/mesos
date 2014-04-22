//
#pragma once
#include <list>
#include <stout/none.hpp>

template <class T> class Option {
public:
  template <class U> Option(U x);
  Option(const std::list<std::basic_string<char> > x);
  Option();
  Option(None);
  bool isSome() const;
  bool isNone() const;
  T get() const ;
  bool operator != (const T &);
};
