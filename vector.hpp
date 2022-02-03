/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 00:13:21 by zineb             #+#    #+#             */
/*   Updated: 2022/01/31 14:16:07 by zzarrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <iterator>
#include "random_access_iterator.hpp"
#include "enable_if.hpp"
#include <algorithm>
#include "reverse_iterator.hpp"
#include <stdexcept>
#include <new>

namespace ft
{


    template <class InputIterator1, class InputIterator2>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
    {
    while (first1!=last1)
    {
        if (first2==last2 || *first2<*first1) return false;
        else if (*first1<*first2) return true;
        ++first1; ++first2;
    }
    return (first2!=last2);
    }
    
    template <class InputIterator1, class InputIterator2>
        bool equal (InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2)
    {
             while (first1!=last1) 
                {
                if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
                    return false;
                ++first1; ++first2;
                }
            return true;     
    }

 
    

    template <class T, class Alloc = std::allocator<T> >

    class Vector
    {
            
    public :
        typedef T value_type;

        typedef    Alloc allocator_type;
        

        typedef T& reference;

        typedef const T& const_reference;

        typedef typename allocator_type::pointer pointer;

        typedef typename allocator_type::const_pointer const_pointer;
        typedef size_t  size_type; 

        typedef ft::random_access_iterator<value_type> iterator;
        typedef ft::random_access_iterator<const value_type>  const_iterator;

        
        typedef ft::reverse_iterator<iterator>  reverse_iterator;


        
        typedef ft::reverse_iterator< const_iterator>  const_reverse_iterator;

        
      size_t size() const
      {
          return _size;
      }
      size_type max_size() const
      {
          return myalloc.max_size();
      }

      // fill constructor
       Vector (const allocator_type& alloc = allocator_type())
      {
          _size = 0;
          _capacity = 0;
          myalloc = alloc;
      }
      Vector (size_type n, const value_type& val = value_type())
      {

          _vec = myalloc.allocate(n);
          _size = n;
          _capacity = n;
          for   (size_t i=0;i<n;i++)
            myalloc.construct(_vec + i, val);
      }
      Vector (const Vector& x)
      {
          this->_size  = 0;
          this->_capacity = 0;
          this->_vec  = NULL;
          if (this == &x)
            return ;
          *this = x;
      }

      template <class InputIterator>
         Vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type(),
                 typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
                {
                    // std::cerr << "range constructor" << std::endl;
                    size_t size = last - first;
                    _vec = myalloc.allocate(size);
                    for(size_t i=0;i<size;i++)
                    {
                         myalloc.construct(&_vec[i], *first); 
                         ++first; 
                    }
                    this->_size = size;
                    this->_capacity = size;
                }

          
        
            reference operator[] (size_t n)
            {
                        
               return (_vec[n]);
               
            }
            const_reference operator[] (size_t n) const
            {
               return (_vec[n]);
            }
            reference at (size_t n)
            {
                if (n >this->size())
                    throw  std::out_of_range("");
                return (_vec[n]);
            }
            const_reference at (size_type n) const
            {
                if (n >this->size())
                    throw  std::out_of_range("");
               return (_vec[n]);
            }
            reference front()
            {
                return (_vec[0]);
            }
            const_reference front() const
            {
                return (_vec[0]);
            }
            reference back()
            {
                return (_vec[this->size() - 1]);
                
            }
            const_reference back() const
            {
                return (_vec[this->size() - 1]);
                
            }
    
            ~Vector()
            {
            
            if (this->_capacity == 0)
                return ;
                for(size_t i = 0; i < _size;i++)
                {
                    myalloc.destroy(_vec + i);
                }
                 myalloc.deallocate( _vec, _capacity);
                
            };
            Vector &operator=(const Vector &rhs)
            {   

                
                if (this->_capacity != 0 )
                {
                
                     for (size_t i=0;i<_size;i++)
                    {
                        myalloc.destroy(_vec + i);  
                    }
                    myalloc.deallocate(_vec,_capacity);
                }

                _size = rhs.size();
                _capacity = rhs.capacity();
                
                if (_capacity != 0 )
                {
                    _vec = myalloc.allocate(_capacity);
                    for (size_t i=0;i<_size;i++)
                    {
                        myalloc.construct(_vec + i, rhs[i]);  
                    }
                }
                return *this;   
            }
          

            allocator_type get_allocator() const
            {
                return myalloc;
            }


            iterator begin()
            {
                return iterator(&_vec[0]);
            }
            const_iterator begin() const
            {
                return const_iterator(&_vec[0]);
            }

             const_iterator end() const
            {
                
                return const_iterator(&_vec[size()]);
            }
            
            iterator end()
            {
                
                return iterator(&_vec[size()]);
            }
            size_t capacity() const
            {
                return _capacity;
            }
            void resize (size_type n, value_type val = value_type())
            {
            
            reserve(n);
                if (this->size() > n)
                {
                    for (size_type i = n ; (i < this->size()) ; i++ )
                    {
                        myalloc.destroy((_vec + i));
                    }
                    this->_size = n;
                }
                else
                {
                    for (size_type i = this->size();  i < n; i++)
                    {
                        myalloc.construct(_vec + i,  val);
                    }
                    this->_size = n;
                }
                this->end()  = this->_vec + this->size();
            }

            
           bool empty() const { 
               if (_size == 0)
                return true;
               else
                return false; 
            }
            iterator insert (iterator position, const value_type& val)
            {
                // iterator tmp(position);
                size_t  pos =  position - begin();
                // std::cout << _size << " " << _capacity << "\n";
                if (!_size)
                    reserve(1);
                else if (this->size() + 1 > this->capacity())
                {
                    reserve(this->capacity() * 2); 
                }
                
               
                int i = this->size();
                while (i > pos)
                {
                    myalloc.construct(_vec +i+1, *(_vec+i));
                    // _vec[i+1] = _vec[i];
                    i--;
                }
                // _vec[pos] = val;
                myalloc.construct(_vec + pos , val);
                _size++;
                //iterator(T *)
                return iterator(_vec + pos);
            }

             void insert (iterator position, size_type n, const value_type& val)
             {
                
                //  check n
                // if (n+size() > max_size())
                //     throw std::bad_alloc();
                int pos = position - begin();
                                //   std::cout << pos << std::endl;

                if (this->size() +n > this->capacity())
                {
                    if (_capacity)
                        reserve(((this->capacity() * 2   >   n ) ? this->capacity() * 2:n+this->capacity() )); 
                    else
                        reserve(n);
                }
                int i = this->size() - 1;
                int j = this->size() + n -1;
                int count = n+size();
                if (_size){
                 
                    while (count > pos)
                    {
                        myalloc.construct(_vec + j, *(_vec + i));
                        j--;
                        i--;
                        count--;
                    }
                }
                 i  = pos;
                //  std::cout << pos << std::endl;
                while (i < pos + n)
                {
                    myalloc.construct(_vec + i, val);
                    _size++;
                    i++;
                }
                // size_t pos ;
                 
                // if (this->size() == 0)
                //     pos  = 0;
                // else 
                //     pos = pos = (&(*position) - this->_vec);

                // if (this->size() + n >= this->capacity())
                // {
                //     if (this->capacity()  == 0)
                //         this->reserve((this->capacity()  + 1) * n );
                //     else
                //             this->reserve(this->capacity() * 2 < n ? this->capacity() + n :  this->capacity() * 2);
                // }
                // if (this->size() != 0)
                // {
                //      size_type j = pos;
                //     for (size_t i =  this->size() - 1; i < this->_size + n ; i++)
                //     {
                //         myalloc.construct(_vec  + i,  this->_vec[j]);
                //         j++;
                //     }
                // }
                // for (size_t i = 0; i < n; i++)
                // {
                //     myalloc.construct(_vec  + pos,  val);
                //     pos++;
                // }
                // this->_size += n;
                // this->end() = this->_vec + this->size();

             }
            //  template <class InputIterator>
            // void insert (iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value_type, InputIterator>::type = InputIterator())
            // {
            //     int i;
            //     int n = last - first;
            //     int pos = pos -begin();
            //     if (this->size() +n > this->capacity())
            //     {
            //         reserve(((this->capacity() * 2   <   n ) ? this->capacity() * 2  : n+this->capcity())  ); 
            //     }
            //     i =pos;
            //     while (i < n)
            //     {
            //         _vec[i]= *first;
            //     }
                
            // } 
        



        // void insert_hlp(iterator position, InputIterator first, InputIterator last, iterator_traits c )
        // {
            
        // }

        //       void insert_hlp(iterator position, InputIterator first, InputIterator last, iterator_traits c )
        // {
            
        // }
        
        
        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
        {
            size_t d = position - begin();
            size_t  n = std::distance(first, last);
            long long j = d;

            
            if ((_size + n) > _capacity)
            {
                if (n > _size)
                    reserve(_capacity + n);
                else
                    reserve(_capacity * 2);
            }
            else if (_size == 0)
                reserve(n);
            for (long long i = _size - 1; i >= j; i--)
                myalloc.construct(&_vec[i + n], _vec[i]);
            for (; first != last; first++)
            {
                myalloc.construct(&_vec[j++], *first);
            }
            _size += n;
        }
        
        
            void reserve (size_type n)
            {
                int i = 0;
                // if (n == 0){
                    
                //     reserve(1);
                // }
                if (n > this->max_size())
                    throw std::length_error("t");
                if (this->capacity() < n)
                {
                    T *tmp = myalloc.allocate(n);
                    while (i < this->size())
                    {
                        // tmp[i] = _vec[i];
                        myalloc.construct(tmp +i , _vec[i]);
                        myalloc.destroy(_vec +i);
                        i++;
                    }
                    if (this->_capacity != 0)
                        myalloc.deallocate(_vec,  _capacity);
                    _vec = tmp;
                    this->_capacity = n;
    
                }
            }
            
           void  push_back (const value_type& val) 
           {
                if (this->_capacity == 0) 
                    reserve(1);
                if (this->_size + 1 > this->_capacity)
                     reserve(this->_capacity * 2);
                // this->_vec[_size] = val;/
                                        myalloc.construct(_vec +_size , val);

                this->_size++;
            }

            void  pop_back() 
            {
                if (this->_capacity == 0 || this->_size == 0)
                    return ;
                myalloc.destroy(&_vec[this->_size]);
                this->_size--;
            }
            iterator erase (iterator position)
            {
                ptrdiff_t diff= position - begin();
                for(size_type i = diff;i<_size -1;i++)
                {
                    myalloc.destroy(_vec + i);
                    myalloc.construct(_vec + i, _vec[i + 1]);
                }
                _size--;
                myalloc.destroy(_vec + _size);
                return  position;
            }
            iterator erase (iterator first, iterator last)
            {
                ptrdiff_t diff = first - begin();
                ptrdiff_t n = last - first;
                for(size_type i = diff;i <n;i++)
                    myalloc.destroy(_vec + i);
                _size = _size - n;
                for(size_type i = diff;i< _size;i++)  
                    _vec[i] = _vec[i + n];
                
                return first;
            }
            void swap (Vector& x)
            {
                std::swap(_capacity, x._capacity);
                std::swap(_size, x._size);
                std::swap(_vec, x._vec);
                
            }
        void clear()
        {
            for(size_type i =0;i<_size;i++)
            {
                myalloc.destroy(_vec + i);
               
            }
            _size = 0;
        }
        void assign (size_type n, const value_type& val)
        {
            // int i;

            // i = 0;
            // clear();
            // reserve(n);
            // while (i < n)
            // {
            //     myalloc.construct(_vec + i, val );
            //     i++;
            // }
            this->clear();
            resize(n , val);
        }

        template <class InputIterator>
        void assign (InputIterator first, InputIterator last)
        {
            // clear();
            // while (first != last)
            // {
            //     this->push_back(*first);
            //     ++first;
            // }
            size_type  n = &(*last)   - &(*first);
                clear();
                reserve(n);
                this->insert(this->begin(), first, last);
        }



        reverse_iterator rbegin()
        {
            return reverse_iterator(this->end());
        }
        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(this->end());
        }

     reverse_iterator rend()
     {
         return reverse_iterator(this->begin());
     }
    const_reverse_iterator rend() const 
    {
                 return const_reverse_iterator(this->begin());

    }


        friend bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
        {
            if (lhs.size() == rhs.size())
                return ft::equal(lhs.begin(),lhs.end(),rhs.begin());
            else
                return false;
        }

        	
       friend bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
        {
            return !(lhs == rhs);
        }

        
        friend bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
        {
            return ft::lexicographical_compare(lhs.begin(),lhs.end() ,  rhs.begin(), rhs.end());
        }

       friend bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
        {
            return !(rhs < lhs); 
        }

       friend bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
        {
            return (rhs < lhs);
        }

        friend bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
        {
            return !(lhs < rhs);
        }
       
                
        private:
            value_type *_vec;
            size_t _size;
            size_t _capacity;
            allocator_type myalloc ;     
    };
            template <class T, class Alloc>
             void swap (ft::Vector<T,Alloc>& x, ft::Vector<T,Alloc>& y)
            {
                x.swap(y);
            }
   
}


//ft::reverse_iterator<std::vector<int>::iterator>
//ft::reverse_iterator<std::vector<int>::iterator>