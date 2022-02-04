/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zineb <zineb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:05:35 by zineb             #+#    #+#             */
/*   Updated: 2022/02/04 12:53:52 by zineb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <functional>
#include "pair.hpp"
namespace ft
{
  template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
  class Map
  {
  public:
    typedef Key key_type;
    typedef T mapped_type;
    typedef ft::pair<const key_type, mapped_type> value_type;
    typedef Compare key_compare;

    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef ptrdiff_t		difference_type;
		typedef size_t			size_type;
    class value_compare
    {
      friend class map;

    protected:
      Compare comp;
      value_compare(Compare c) : comp(c) {}

    public:
      typedef bool result_type;
      typedef value_type first_argument_type;
      typedef value_type second_argument_type;

      bool operator()(const value_type &x, const value_type &y) const
      {
        return comp(x.first, y.first);
      }
      
    };


    
  };
}