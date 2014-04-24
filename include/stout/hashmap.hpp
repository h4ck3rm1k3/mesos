template <class K,class V> class hashmap {
public:
  template <class T> V & operator [] (const T &) const ;
  template <class T> void erase(const T &) const ;
  template <class T> int count(const T &) const ;
  
};
