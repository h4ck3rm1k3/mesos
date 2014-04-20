//
#pragma once

#include <iostream>

std::ostream VLOG(int);

template <class T> std::ostream CHECK(T);
template <class T,class U> std::ostream CHECK_NE(T,U);
template <class T,class U> std::ostream CHECK_EQ(T,U);
template <class T> std::ostream LOG(T);


//template <class T> std::ostream INFO(T);

enum levels {
  INFO,
};


//std::ostream LOG(levels);
