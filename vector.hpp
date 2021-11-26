/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 00:13:21 by zineb             #+#    #+#             */
/*   Updated: 2021/11/26 19:57:09 by zzarrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <iterator>

namespace ft
{

    template <class T, class Alloc = std::allocator<T>>

    class vector
    {
    private:
            T *_vec;
            size_t n;

        typedef T value_type;

        typedef Alloc allocator_type;

        typedef allocator_type::reference reference;

        typedef allocator_type::const_reference const_reference;

        typedef typenameallocator_type::pointer pointer;

        typedef allocator_type::const_pointer const_pointer;

        typedef ft::random_access_iterator<value_type> iterator
        typedef ft::random_access_iterator<const value_type>  const_iterator;
        
        

            public : 
            vector(int c)
            {
                _vec = Alloc.allocate(c);
                n = 0;
            }
            void push_back(T c)
            {
                this->_vec[size] = c;
                size++;
            }
            ~vector();

            vector(const vector &cp);

            vector &operator=(const vector &rhs);

            void get_allocator();


            random_access_iterator begin()
            {
                return random_access_iterator(&_vec[0]);
            }
            
            
    };

    vector::vector(/* args */)
    {
    }

    vector::~vector()
    {
    }
}
