//
#pragma once
#include <list>
#include <stout/none.hpp>

template <class T> class Option {
public:
  Option(const std::list<std::basic_string<char> > x);
  Option();
  Option(None);
  bool isSome();
  T get();
};
