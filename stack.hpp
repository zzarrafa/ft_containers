/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:50:47 by zzarrafa          #+#    #+#             */
/*   Updated: 2021/12/23 15:59:20 by zzarrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <iterator>
#include "random_access_iterator.hpp"
#include "vector.hpp"

namespace ft
{
  template <class T, class Container = Vector<T> >
  class Stack
  {
  public:
    typedef T value_type;
    typedef Container container_type;
    typedef size_t size_type;

  public:
    explicit Stack(const container_type &ctnr = container_type()) : _cont(ctnr) {}
    ~Stack() {}
    bool empty() const
    {
      return (_cont.empty());
    }
    size_type size() const
    {
      return (_cont.size());
    }
    value_type &top()
    {
      return (_cont.back());
    }
    const value_type &top() const
    {
      return (_cont.back());
    }
    void push(const value_type &val)
    {
      _cont.push_back(val);
    }
    void pop()
    {
      _cont.pop_back();
    }
    // template <class U, class Container1>
    // friend bool operator==(const Stack<U, Container1> &lhs, const Stack<U, Container1> &rhs);
    // template <class U, class Container1>
    // friend bool operator!=(const Stack<U, Container1> &lhs, const Stack<U, Container1> &rhs);
    // template <class U, class Container1>
    // friend bool operator<(const Stack<U, Container1> &lhs, const Stack<U, Container1> &rhs);
    // template <class U, class Container1>
    // friend bool operator<=(const Stack<U, Container1> &lhs, const Stack<U, Container1> &rhs);
    // template <class U, class Container1>
    // friend bool operator>(const Stack<U, Container1> &lhs, const Stack<U, Container1> &rhs);
    // template <class U, class Container1>
    // friend bool operator>=(const Stack<U, Container1> &lhs, const Stack<U, Container1> &rhs);

  protected:
    container_type _cont;
  };
  template <class T, class Container>
  bool operator==(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
  {
    return (lhs._cont == rhs._cont);
  }
  template <class T, class Container>
  bool operator!=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
  {
    return (lhs._cont != rhs._cont);
  }
  template <class T, class Container>
  bool operator<(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
  {
    return (lhs._cont < rhs._cont);
  }
  template <class T, class Container>
  bool operator<=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
  {
    return (lhs._cont <= rhs._cont);
  }
  template <class T, class Container>
  bool operator>(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
  {
    return (lhs._cont > rhs._cont);
  }
  template <class T, class Container>
  bool operator>=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
  {
    return (lhs._cont >= rhs._cont);
  }
}