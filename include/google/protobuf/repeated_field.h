
namespace google {
  namespace protobuf { 
    template <class T> class RepeatedPtrField {
    public:

      class const_iterator {
      public:
        //template <class U> bool operator!=( U & ) ;
        operator T ();
        T operator *  ();
        const_iterator operator ++  ();
      };


      class iterator {
      public:
        operator const_iterator();
        //template <class U> bool operator!=( U & ) ;
        operator T ();
        T operator *  ();
        iterator operator ++  ();
      };

      iterator begin() const;
      iterator end() const;

      template <class U> void MergeFrom(U);
      void Clear();
      RepeatedPtrField<T> * Add();

      T Get(int &) const;
      size_t size() const;
    };
  }
}
