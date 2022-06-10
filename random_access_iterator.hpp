/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:49:48 by zzarrafa          #+#    #+#             */
/*   Updated: 2022/03/01 10:41:31 by zzarrafa         ###   ########.fr       */
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
        
        
                random_access_iterator()
                {
                    _ptr = NULL;
                }
                
                operator random_access_iterator<const T>()
                {
                    return random_access_iterator<const T>(_ptr);
                }

                random_access_iterator (pointer p)
                {
                    this->_ptr = p;
                }

                random_access_iterator ( const random_access_iterator   &itr)
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




 



