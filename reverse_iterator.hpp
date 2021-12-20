/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:20:28 by zzarrafa          #+#    #+#             */
/*   Updated: 2021/12/20 15:29:38 by zzarrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <iterator>

template <class Iterator> 
class reverse_iterator
{
    private:
    Iterator ite;
    
    public:
    typedef Iterator iterator_type;
  typedef typename Iterator::pointer pointer;
  typedef typename Iterator::reference reference;
  typedef typename Iterator::size_type size_type;
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::iterator_category iterator_category;

  
  reverse_iterator() : ite()
  {   
  }
  reverse_iterator(const iterator_type const &c) : ite(c)
  {}

  reverse_iterator(const reverse_iterator &cp) : ite(cp.ite){}
  template <typename Iter>
  reverse_iterator(const reverse_iterator<Iter> &x) : ite(x.base()) {}
  ~reverse_iterator();
  reverse_iterator &operator=(const reverse_iterator &x)
  {
    Iterator::operator=(x);
    return *this;
  }
  iterator_type base() const 
  {
       return this->ite; 
  }
  reference operator*() const
  {
      return *ite;
  }
  pointer operator->() const
  {
    return &operator*();
  }
  reverse_iterator& operator++()
  {
      --ite;
    return *this;
  }
reverse_iterator  operator++(int)
{
    reverse_iterator out(*this);
    --ite;
    return out;
}
reverse_iterator& operator--()
{
    ++ite;
    return *this;
}
reverse_iterator  operator--(int)
{
    reverse_iterator out(*this);
    ++ite;
    return out;
}
  
    
}