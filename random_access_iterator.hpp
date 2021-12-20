/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:49:48 by zzarrafa          #+#    #+#             */
/*   Updated: 2021/12/20 21:49:17 by zzarrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <iterator>

namespace ft
{
    template <class T>
    class random_access_iterator: public std::iterator<std::input_iterator_tag, T>
    {
        public:
            typedef T         value_type;
            typedef ptrdiff_t  difference_type;
            typedef T  * pointer;
            typedef T &reference;
            // typedef Category  iterator_category;

                random_access_iterator()
                {
                    _ptr = NULL;
                }


                random_access_iterator (pointer p)
                {
                    this->_ptr = p;
                }

                random_access_iterator ( random_access_iterator  const &itr)
                {
                    this->_ptr = itr.base();
                }
                pointer base()
                {
                    return this->_ptr;
                }

                 pointer base() const
                {
                    return this->_ptr;
                }
                
                
              value_type & operator *()
                {
                    return *_ptr;
                }
                value_type* operator->() const 
                {
                    return _ptr;
                }
                value_type& operator[](difference_type rhs) const 
                {
                    return _ptr[rhs];
                }
            random_access_iterator& operator+=(difference_type rhs) 
            {
                _ptr += rhs;
                 return *this;
            }
            random_access_iterator& operator-=(difference_type rhs) 
            {
                _ptr -= rhs;
                 return *this;
            }
            random_access_iterator& operator++() 
            {
                ++_ptr;
                 return *this;
            }
            random_access_iterator& operator--() 
            {
                --_ptr;
                 return *this;
            }
            random_access_iterator operator++(int) 
            {
                random_access_iterator tmp(*this); ++_ptr; 
                return tmp;
            }
            random_access_iterator operator--(int) 
            {
                random_access_iterator tmp(*this); --_ptr; 
                return tmp;
            }
            difference_type operator-(const random_access_iterator& rhs) const 
            {
                return _ptr-rhs._ptr;
            }
            random_access_iterator operator+(difference_type rhs) const 
            {
                return random_access_iterator(_ptr+rhs);
            }
            random_access_iterator operator-(difference_type rhs) const 
            {
                return random_access_iterator(_ptr-rhs);
            }
            friend     difference_type operator+( const random_access_iterator &lhs, const random_access_iterator& rhs) 
            {
                return lhs._ptr - rhs._ptr;
            }
       friend     random_access_iterator operator+(difference_type lhs, const random_access_iterator& rhs) 
            {
                return random_access_iterator(lhs+rhs._ptr);
            }
      friend      random_access_iterator operator-(difference_type lhs, const random_access_iterator& rhs)
             {
                 return random_access_iterator(lhs-rhs.base());
             }
             bool operator==(const random_access_iterator& rhs) const 
             {
                 return _ptr == rhs._ptr;
             }
            bool operator!=(const random_access_iterator& rhs) const
             {
                 return _ptr != rhs._ptr;
             }
            bool operator>(const random_access_iterator& rhs) const 
            {
                return _ptr > rhs._ptr;
            }
            bool operator<(const random_access_iterator& rhs) const 
            {
                return _ptr < rhs._ptr;
            }
            bool operator>=(const random_access_iterator& rhs) const {
                return _ptr >= rhs._ptr;
                }
            bool operator<=(const random_access_iterator& rhs) const 
            {
                return _ptr <= rhs.base();
            }
            


            private:
                T *_ptr;
    };
};


// template <typename T>
// class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
// {
// public:
//     /* Category of the iterator. */
//     typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;

//     /* Type of elements pointed. */
//     typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;

//     /* Type to represent the difference between two iterators. */
//     typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;

//     /* Type to represent a pointer to an element pointed */
//     typedef T *pointer;

//     /* Type to represent a reference to an element pointed */
//     typedef T &reference;

//     /*


 



//   template<typename Type>
// class Container<Type>::Iterator : public std::iterator<std::random_access_iterator_tag, Type>
// {
// public:
//     using difference_type = typename std::iterator<std::random_access_iterator_tag, Type>::difference_type;
    
//     Iterator() : _ptr(nullptr) {}
//     Iterator(Type* rhs) : _ptr(rhs) {}
//     Iterator(const Iterator &rhs) : _ptr(rhs._ptr) {}
//     /* inline Iterator& operator=(Type* rhs) {_ptr = rhs; return *this;} */
//     /* inline Iterator& operator=(const Iterator &rhs) {_ptr = rhs._ptr; return *this;} */
//     inline Iterator& operator+=(difference_type rhs) {_ptr += rhs; return *this;}
//     inline Iterator& operator-=(difference_type rhs) {_ptr -= rhs; return *this;}
//     inline Type& operator*() const {return *_ptr;}
//     inline Type* operator->() const {return _ptr;}
//     inline Type& operator[](difference_type rhs) const {return _ptr[rhs];}
    
//     inline Iterator& operator++() {++_ptr; return *this;}
//     inline Iterator& operator--() {--_ptr; return *this;}
//     inline Iterator operator++(int) const {Iterator tmp(*this); ++_ptr; return tmp;}
//     inline Iterator operator--(int) const {Iterator tmp(*this); --_ptr; return tmp;}
//     /* inline Iterator operator+(const Iterator& rhs) {return Iterator(_ptr+rhs.ptr);} */
//     inline difference_type operator-(const Iterator& rhs) const {return _ptr-rhs.ptr;}
//     inline Iterator operator+(difference_type rhs) const {return Iterator(_ptr+rhs);}
//     inline Iterator operator-(difference_type rhs) const {return Iterator(_ptr-rhs);}
//     friend inline Iterator operator+(difference_type lhs, const Iterator& rhs) {return Iterator(lhs+rhs._ptr);}
//     friend inline Iterator operator-(difference_type lhs, const Iterator& rhs) {return Iterator(lhs-rhs._ptr);}
    
//     inline bool operator==(const Iterator& rhs) const {return _ptr == rhs._ptr;}
//     inline bool operator!=(const Iterator& rhs) const {return _ptr != rhs._ptr;}
//     inline bool operator>(const Iterator& rhs) const {return _ptr > rhs._ptr;}
//     inline bool operator<(const Iterator& rhs) const {return _ptr < rhs._ptr;}
//     inline bool operator>=(const Iterator& rhs) const {return _ptr >= rhs._ptr;}
//     inline bool operator<=(const Iterator& rhs) const {return _ptr <= rhs._ptr;}
// private:
//     Type* _ptr;
// };