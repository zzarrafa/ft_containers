/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 00:13:21 by zineb             #+#    #+#             */
/*   Updated: 2021/12/20 19:11:28 by zzarrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <iterator>
#include "random_access_iterator.hpp"
#include "enable_if.hpp"

namespace ft
{

    template <class T, class Alloc = std::allocator<T> >

    class vector
    {
            
    public :
        typedef T value_type;

        typedef    Alloc allocator_type;
        

        typedef typename allocator_type::reference reference;

        typedef typename allocator_type::const_reference const_reference;

        typedef typename allocator_type::pointer pointer;

        typedef typename allocator_type::const_pointer const_pointer;
        typedef size_t  size_type; 

        typedef ft::random_access_iterator<value_type> iterator;
        typedef ft::random_access_iterator<const value_type>  const_iterator;
        
      size_t size()
      {
          return _size;
      }
      size_type max_size() const
      {
          return myalloc.max_size();
      }

      
       vector (const allocator_type& alloc = allocator_type())
      {
          _size = 0;
          _capacity = 0;
          myalloc = alloc;
      }
      vector (size_type n, const value_type& val = value_type())
      {
          _vec = myalloc.allocate(n);
          _size = n;
          _capacity = n;
          for   (size_t i=0;i<=n;i++)
            myalloc.construct(_vec + i, n);
      }
      vector (const vector& x)
      {
          _size = x.size();
          _vec = myalloc.allocate(_size);
          _capacity = x.capacity();
          for   (size_t i=0;i<=_size;i++)
          {
          myalloc.construct(_vec + i, x);  
        }
          
      }

      template <class InputIterator>
         vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type())
                {
                    size_t size = &(*last) - &(*first);
                    _vec = myalloc.alloc(size);
                    for(size_t i=0;i<size;i++)
                    {
                         myalloc.construct(_vec + i, *first); 
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
                // _vec = myalloc.allocate(n);
               return (_vec[n]);
            }
            const_reference at (size_type n) const
            {
                if (n >this->size())
                    throw "implment me";
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
    
            ~vector()
            {

                for(size_t i = 0; i < _size;i++)
                {
                    myalloc.destroy(_vec + i);
                }
                        myalloc.deallocate( _vec, _capacity);
                
            };


            vector &operator=(const vector &rhs);

            void get_allocator();


            iterator begin()
            {
                return iterator(&_vec[0]);
            }
            const_iterator begin() const
            {
                return iterator(&_vec[0]);
            }

             const_iterator end() const
            {
                
                return iterator(&_vec[size()]);
            }
            
            iterator end()
            {
                
                return iterator(&_vec[size()]);
            }
            size_t capacity()
            {
                return _capacity;
            }
            void resize (size_type n, value_type val = value_type())
            {
                if (n > this->capacity())
                {
                    reserve(n);
                    
                
                }
                else {
                    int i = n;
                    while (i <this->size())
                    {
                        myalloc.destroy(*_vec + i);
                        i++;
                    }
                    // rest size
                    
                }
            }
           bool empty() const { 
               if (_size == 0)
                return true;
               else
                return false; 
            }
            iterator insert (iterator position, const value_type& val)
            {
                if (this->size() +1 > this->capacity())
                {
                    reserve(this->capacity() * 2); 
                }
                size_t  pos = _vec - &(*position);
                
                int i = this->size();
                while (i >= pos)
                {
                    _vec[i+1] = _vec[i];
                    i--;
                }
                _vec[pos] = val;
                //iterator(T *)
                return iterator(_vec + pos);
            }

             void insert (iterator position, size_type n, const value_type& val)
             {
                
                 //check n
                if (this->size() +n > this->capacity())
                {
                    reserve(((this->capacity() * 2   <   n ) ? this->capacity() * 2  : n+this->capcity())  ); 
                }
                int i = this->size();
                int j = this->size() + n;
                int count = 0;
                while (count < n)
                {
                    _vec[j] = _vec[i];
                    j--;
                    i--;
                    count++;
                }
                
             }
             template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value_type, InputIterator>::type = InputIterator())
            {
                int i;
                int n = last - first;
                int pos = pos -begin();
                if (this->size() +n > this->capacity())
                {
                    reserve(((this->capacity() * 2   <   n ) ? this->capacity() * 2  : n+this->capcity())  ); 
                }
                i =pos;
                while (i < n)
                {
                    _vec[i]= *first;
                }
                
            }  
            void reserve (size_type n)
            {
                int i = 0;
                if (this->capacity() < n)
                {
                    T *tmp = myalloc.allocate(n);
                    while (i < this->size())
                    {
                        tmp[i] = _vec[i];
                        i++;
                    }
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
                this->_vec[_size] = val;
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
                
            }
        
        private:
            value_type *_vec;
            size_t _size;
            size_t _capacity;
            allocator_type myalloc ;     
    };

   
}
