
template <class T, class U> void doforeach(T,U) {}
template <class T, class U> T first(U);
template <class U> bool not_end( U);
template <class U> void get_next( U);


#define foreach(P, X,Y)                          \
  for (X = first<P>(Y);                        \
      not_end(Y); \
      get_next(Y)) 

