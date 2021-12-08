/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 00:13:21 by zineb             #+#    #+#             */
/*   Updated: 2021/12/06 22:50:15 by zzarrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <iterator>
#include "random_access_iterator.hpp"

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

        // typedef allocator_type::const_pointer const_pointer;

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
      vector (size_type n, const value_type& val = value_type()
      {
          _vec = myalloc.allocate(c);
          _size = n;
          _capacity = n;
          for   (size_t i=0;i<=n;i++;)
          {
          myalloc.construct(_vec + i, n);
              
          }
      }
      vector (const vector& x)
      {
          _size = x.size();
          _vec = myalloc.allocate(_size);
          _capacity = x.capacity()  
          for   (size_t i=0;i<=_size;i++;)
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
                return (_vec[0])
            }
            const_reference front() const
            {
                return (_vec[0])
            }
            reference back()
            {
                return (_vec[this->size() - 1])
                
            }
            // vector(int c)
            // {
            //     _vec = myalloc.allocate(c);
            //     // n = 0;
            // }
            void push_back(T c)
            {
                // this->_vec[_size] = c;

                //check if reach the capacity
                myalloc.construct(_vec+_size, c );
                _size++;
            }
            ~vector()
            {

                for(size_t i = 0; i < _size;i++)
                {
                    myalloc.destroy(_vec + i);
                }
                        myalloc.deallocate( _vec, _capacity);
                
            };

            vector(const vector &cp) 
            {
                 _vec = myalloc.allocate(cp.capacity());
                
            }

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
                
                return iterator(&_vec[size()])
            }
            
            iterator end()
            {
                
                return iterator(&_vec[size()])
            }
            size_t capacity()
            {
                return _capacity;
            }
            void resize (size_type n, value_type val = value_type())
            {
                
            }


            


        private:
            value_type *_vec;
            size_t _size;
            size_t _capacity;
            allocator_type myalloc;
            
    };

   
}
