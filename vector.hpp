/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zineb <zineb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 00:13:21 by zineb             #+#    #+#             */
/*   Updated: 2021/11/24 22:29:26 by zineb            ###   ########.fr       */
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
        typedef T value_type;

        typedef Alloc allocator_type;

        typedef allocator_type::reference reference;

        typedef allocator_type::const_reference const_reference;

        typedef typenameallocator_type::pointer pointer;

        typedef allocator_type::const_pointer const_pointer;

        typedef ft::random_access_iterator<value_type> iterator
            //    typedef std::random_access_iterator_tag  const_iterator;

            public : vector(/* args */);
        ~vector();

        vector(const vector &cp);

        vector &operator=(const vector &rhs);

        void get_allocator();
    };

    vector::vector(/* args */)
    {
    }

    vector::~vector()
    {
    }
}
