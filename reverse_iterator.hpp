/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:20:28 by zzarrafa          #+#    #+#             */
/*   Updated: 2021/12/23 18:29:22 by zzarrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <iterator>
namespace ft{

template <class Iterator> 
class reverse_iterator
{
    private:
    Iterator ite;
    
    public:
    typedef Iterator iterator_type;
  typedef typename Iterator::pointer pointer;
  typedef typename Iterator::reference reference;
  // typedef typename Iterator::const_reference const_reference;
  typedef  size_t size_type;
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::iterator_category iterator_category;

  
  reverse_iterator() : ite(0)
  {   
  }
  reverse_iterator(const iterator_type  &c) : ite(c)
  {}

  // ~reverse_iterator(){}

  reverse_iterator(const reverse_iterator &cp) : ite(cp.ite){}
  template <typename Iter>
  reverse_iterator(const reverse_iterator<Iter> &x) : ite(x.base()) {}
  ~reverse_iterator(){};
  reverse_iterator &operator=(const reverse_iterator &x)
  {
    this->ite = x.base();
    return *this;
  }
  iterator_type base() const 
  {
    iterator_type tmp(ite);
       return tmp++; 
  }
  reference operator*() 
  {
    Iterator c = ite;
    --c;
      return *c;
  }

   const reference operator*()  const
  {
          Iterator c = ite;
    --c;
      return *c;
  }
const  pointer operator->() const
  {
          Iterator c = ite;
    --c;
    return &(*c);
  }
    pointer operator->() 
  {
        Iterator c = ite;
    --c;
    return &(*c);
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
            reverse_iterator  operator-(size_t n) 
            {
                return reverse_iterator(ite + n );
            }


            //           reverse_iterator  operator-(reverse_iterator n) 
            // {
            //     return reverse_iterator(ite - n.base() );
            // }
            reverse_iterator  operator+(difference_type n) 
            {
                return reverse_iterator(ite -n );
            }

             bool operator==(const reverse_iterator& rhs) const 
             {
                 return ite == rhs.base();
             }
            bool operator!=(const reverse_iterator& rhs) const
             {
                 return ite != rhs.base();
             }
            bool operator>(const reverse_iterator& rhs) const 
            {
                return ite < rhs.base();
            }
            bool operator<(const reverse_iterator& rhs) const 
            {
                return ite > rhs.base();
            }
            bool operator>=(const reverse_iterator& rhs) const {
                return ite <= rhs.base();
                }
            bool operator<=(const reverse_iterator& rhs) const 
            {
                return ite >= rhs.base();
            }

               reverse_iterator &operator+=(difference_type n)
            {
                ite -= n;
                return (*this);
            }

            reverse_iterator &operator-=(difference_type n)
            {
                ite +=n;
                return (*this);
            }
		      reference			operator [] (difference_type n)			
            	{ return (*(ite - n -1)); }

               friend     reverse_iterator operator+( difference_type n, const reverse_iterator& rhs) 
            {
                return reverse_iterator(rhs.base() - n);
            }

                friend     difference_type operator-( const reverse_iterator &lhs, const reverse_iterator& rhs) 
            {
                return rhs.base() - lhs.base();
            }
            operator    reverse_iterator<const iterator_type>() const{
                    //std::cout << "reverse iterator conversion operator" << std::endl;
                    return reverse_iterator<const iterator_type>(ite);
                }
    //    friend     reverse_iterator operator+(difference_type lhs, const reverse_iterator& rhs) 
    //         {
    //             return reverse_iterator(lhs+rhs.base());
    //         }
    //   friend      reverse_iterator operator-(size_t lhs, const reverse_iterator& rhs)
    //          {
    //              return reverse_iterator(lhs-rhs.base());
    //          }

        
  
    
};}