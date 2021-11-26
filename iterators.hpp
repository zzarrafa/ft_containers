/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:49:48 by zzarrafa          #+#    #+#             */
/*   Updated: 2021/11/26 20:09:10 by zzarrafa         ###   ########.fr       */
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
    class random_access_iterator: public std::iterator<std::input_iterator_tag, int>
    {
        public:
            typedef T         value_type;
            typedef ptrdiff_t  difference_type;
            typedef T  * pointer;
            typedef T &reference;
            typedef Category  iterator_category;

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
                

              value_type  operator *()
                {
                    return *_ptr;
                }
                


            private:
                T *_ptr;
    }
}

}
template <typename T>
class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
{
public:
    /* Category of the iterator. */
    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;

    /* Type of elements pointed. */
    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;

    /* Type to represent the difference between two iterators. */
    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;

    /* Type to represent a pointer to an element pointed */
    typedef T *pointer;

    /* Type to represent a reference to an element pointed */
    typedef T &reference;

    /*

    -------------------------

    template<typename Type>
class Container<Type>::Iterator : public std::iterator<std::random_access_iterator_tag, Type>
{
public:
    using difference_type = typename std::iterator<std::random_access_iterator_tag, Type>::difference_type;
    
    Iterator() : _ptr(nullptr) {}
    Iterator(Type* rhs) : _ptr(rhs) {}
    Iterator(const Iterator &rhs) : _ptr(rhs._ptr) {}
    /* inline Iterator& operator=(Type* rhs) {_ptr = rhs; return *this;} */
    /* inline Iterator& operator=(const Iterator &rhs) {_ptr = rhs._ptr; return *this;} */
    inline Iterator& operator+=(difference_type rhs) {_ptr += rhs; return *this;}
    inline Iterator& operator-=(difference_type rhs) {_ptr -= rhs; return *this;}
    inline Type& operator*() const {return *_ptr;}
    inline Type* operator->() const {return _ptr;}
    inline Type& operator[](difference_type rhs) const {return _ptr[rhs];}
    
    inline Iterator& operator++() {++_ptr; return *this;}
    inline Iterator& operator--() {--_ptr; return *this;}
    inline Iterator operator++(int) const {Iterator tmp(*this); ++_ptr; return tmp;}
    inline Iterator operator--(int) const {Iterator tmp(*this); --_ptr; return tmp;}
    /* inline Iterator operator+(const Iterator& rhs) {return Iterator(_ptr+rhs.ptr);} */
    inline difference_type operator-(const Iterator& rhs) const {return _ptr-rhs.ptr;}
    inline Iterator operator+(difference_type rhs) const {return Iterator(_ptr+rhs);}
    inline Iterator operator-(difference_type rhs) const {return Iterator(_ptr-rhs);}
    friend inline Iterator operator+(difference_type lhs, const Iterator& rhs) {return Iterator(lhs+rhs._ptr);}
    friend inline Iterator operator-(difference_type lhs, const Iterator& rhs) {return Iterator(lhs-rhs._ptr);}
    
    inline bool operator==(const Iterator& rhs) const {return _ptr == rhs._ptr;}
    inline bool operator!=(const Iterator& rhs) const {return _ptr != rhs._ptr;}
    inline bool operator>(const Iterator& rhs) const {return _ptr > rhs._ptr;}
    inline bool operator<(const Iterator& rhs) const {return _ptr < rhs._ptr;}
    inline bool operator>=(const Iterator& rhs) const {return _ptr >= rhs._ptr;}
    inline bool operator<=(const Iterator& rhs) const {return _ptr <= rhs._ptr;}
private:
    Type* _ptr;
};
  