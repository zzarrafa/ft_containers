/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:38:55 by zzarrafa          #+#    #+#             */
/*   Updated: 2022/02/02 16:18:03 by zzarrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once

namespace ft
{
  template <class T1, class T2>
  struct pair
  {
  public:
    typedef T1 first_type;
    typedef T2 second_type;

    first_type first;
    second_type second;
    pair() : first(), second()
    {
    }
    template <class U, class V>
    pair(const pair<U, V> &pr) : first(pr.first), second(pr.second)
    {
    }
    pair(const first_type &x, const second_type &y) : first(x), second(y)
    {
    }
    pair &operator=(const pair &rh)
    {
      this->first = rh.first;
      this->second = rh.second;
      return (*this);
    }
  };
  template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
      return ( pair<T1,T2>(x,y) );
    }
  template<class T1, class T2>
    std::ostream &operator << (std::ostream& o, const pair<T1, T2> &p){
      o << "(" << p.first << "," << p.second << ")";
      return o;
    }
  
}