
// template <class Iterator>
// class reverse_iterator
// {
// protected:
//   Iterator current;

// public:
//   typedef Iterator iterator_type;
//   typedef typename Iterator::pointer pointer;
//   typedef typename Iterator::reference reference;
//   typedef typename Iterator::size_type size_type;
//   typedef typename Iterator::difference_type difference_type;
//   typedef typename Iterator::iterator_category iterator_category;

//   reverse_iterator() : current() {}
//   reverse_iterator(const iterator_type &x) : current(x) {}
//   reverse_iterator(const reverse_iterator &x) : current(x.current) {}
//   template <typename Iter>
//   reverse_iterator(const reverse_iterator<Iter> &x) : current(x.base()) {} //.base() returns the underlying iterator
//   ~reverse_iterator() {}
//   reverse_iterator &operator=(const reverse_iterator &x)
//   {
//     Iterator::operator=(x);
//     return *this;
//   }
//   iterator_type base() const { return this->current; }

//   reference operator*()
//   {
//     return *current;
//   }
//   pointer operator->()
//   {
//     return &operator*();
//   }
//   reverse_iterator &operator++()
//   {
//     --current;
//     return *this;
//   }
//   reverse_iterator operator++(int)
//   {
//     reverse_iterator out(*this);
//     --current;
//     return out;
//   }
//   reverse_iterator &operator--()
//   {
//     ++current;
//     return *this;
//   }
//   reverse_iterator operator--(int)
//   {
//     reverse_iterator out(*this);
//     ++current;
//     return out;
//   }
// };
// template <typename Iterator>
// inline bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
// {
//   return (lhs.base() == rhs.base());
// }
// template <typename Iterator>
// inline bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
// {
//   return (rhs.base() < lhs.base());
// }
// template <typename Iterator>
// inline bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
// {
//   return !(lhs == rhs);
// }
// template <typename Iterator>
// inline bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
// {
//   return (rhs < lhs);
// }
// template <typename Iterator>
// inline bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
// {
//   return !(rhs < lhs);
// }
// template <typename Iterator>
// inline bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
// {
//   return !(lhs < rhs);
// }
// // Comparison of reverse_iterator to const reverse iterator
// template <typename IteratorL, typename IteratorR>
// inline bool operator==(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
// {
//   return (lhs.base() == rhs.base());
// }
// template <typename IteratorL, typename IteratorR>
// inline bool operator<(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
// {
//   return (rhs.base() < lhs.base());
// }
// template <typename IteratorL, typename IteratorR>
// inline bool operator!=(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
// {
//   return !(lhs == rhs);
// }
// template <typename IteratorL, typename IteratorR>
// inline bool operator>(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
// {
//   return (rhs < lhs);
// }
// template <typename IteratorL, typename IteratorR>
// inline bool operator<=(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
// {
//   return !(rhs < lhs);
// }
// template <typename IteratorL, typename IteratorR>
// inline bool operator>=(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
// {
//   return !(lhs < rhs);
// }
// // Generator function for reverse_iterator
// template <typename Iterator>
// inline reverse_iterator<Iterator> make_reverse_iterator(Iterator i)
// {
//   return reverse_iterator<Iterator>(i);
// }

// template <class Iterator>
// class ReverseRAI : public reverse_iterator<Iterator>
// {
// public:
//   typedef reverse_iterator<Iterator> Base;
//   typedef Iterator iterator_type;
//   using typename Base::difference_type;
//   using typename Base::iterator_category;
//   using typename Base::pointer;
//   using typename Base::reference;
//   using typename Base::size_type;

//   ReverseRAI() : Base() {}
//   ReverseRAI(const iterator_type &x) : Base(x) {}
//   ReverseRAI(const ReverseRAI &x) : Base(x.current) {}
//   template <typename Iter>
//   ReverseRAI(const ReverseBI<Iter> &x) : Base(x.base()) {} //.base() returns the underlying iterator
//   ~ReverseRAI() {}
//   ReverseRAI &operator=(const ReverseRAI &x)
//   {
//     Iterator::operator=(x);
//     return *this;
//   }

//   ReverseRAI operator+(difference_type n) const
//   {
//     return ReverseRAI(this->current - n);
//   }
//   ReverseRAI &operator+=(difference_type n)
//   {
//     this->current -= n;
//     return *this;
//   }
//   ReverseRAI operator-(difference_type n) const
//   {
//     return ReverseRAI(this->current + n);
//   }
//   ReverseRAI &operator-=(difference_type n)
//   {
//     this->current += n;
//     return *this;
//   }
//   reference operator[](difference_type n)
//   {
//     return *(*this + n);
//   }
// };

// template <typename Iterator>
// inline typename ReverseRAI<Iterator>::difference_type operator-(const ReverseRAI<Iterator> &lhs, const ReverseRAI<Iterator> &rhs)
// {
//   return (lhs.base() - rhs.base());
// }
// template <typename IteratorL, typename IteratorR>
// inline typename ReverseRAI<IteratorL>::difference_type operator-(const ReverseRAI<IteratorL> &lhs, const ReverseRAI<IteratorR> &rhs)
// {
//   return (lhs.base() - rhs.base());
// }

// template <typename Iterator>
// inline ReverseRAI<Iterator> operator+(typename ReverseRAI<Iterator>::difference_type n, const ReverseRAI<Iterator> &x)
// {
//   return ReverseRAI<Iterator>(x.base() - n);
// }
// #include "vector.hpp"
// #include "random_access_iterator.hpp"



// int main ()
// {
//   unsigned int i;
//   ft::Vector<int> foo (3,100);   // three ints with a value of 100
//   ft::Vector<int> bar (5,200);   // five ints with a value of 200

//   foo.swap(bar);

//   std::cout << "foo contains:";
//   for (ft::Vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   std::cout << "bar contains:";
//   for (ft::Vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }
// #include "stack.hpp"
// int main ()
// {
//   ft::Stack<int> mystack;
//   int sum (0);

//   for (int i=1;i<=10;i++) mystack.push(i);

//   while (!mystack.empty())
//   {
//      sum += mystack.top();
//      mystack.pop();
//   }

//   std::cout << "total: " << sum << '\n';

//   return 0;
// }