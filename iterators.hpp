/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zineb <zineb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:49:48 by zzarrafa          #+#    #+#             */
/*   Updated: 2021/11/24 22:33:31 by zineb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <iterator>

namespace ft
{
    template <class Iter>
    class iterator_traits
    {
        typedef
    }
}
namespace ft
{
    template <class Iterator>

    class reverse_iterator
    {
    private:
        typedef Iterator iterator_type;
        typedef iterator_traits<Iterator>::iterator_category
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