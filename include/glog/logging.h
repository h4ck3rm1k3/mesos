//
#pragma once

#include <iostream>

std::ostream & VLOG(int);
template <class T> std::ostream & CHECK(T);
template <class T> std::ostream & CHECK_SOME(T);
template <class T> T CHECK_NOTNULL(T);
template <class T> std::ostream & EXIT(T);
template <class T,class U> std::ostream &CHECK_NE(T,U);
template <class T,class U> std::ostream & CHECK_EQ(T,U);
template <class T> std::ostream & LOG(T);


//template <class T> std::ostream INFO(T);

enum levels {
  INFO,
  FATAL,
  WARNING,
  ERROR,
};


//std::ostream LOG(levels);
