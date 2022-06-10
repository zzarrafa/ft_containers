/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:50:47 by zzarrafa          #+#    #+#             */
/*   Updated: 2022/03/01 12:16:09 by zzarrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <iterator>
#include "random_access_iterator.hpp"
#include "vector.hpp"


namespace  ft {
template <class T, class Container =  ft::Vector<T> > class Stack
{

    public :
    typedef T  value_type;
    typedef Container container_type;
    typedef  size_t  size_type;


    explicit Stack (const container_type& con = container_type())
    {
        _container = con;
    }


    bool empty() const
    {
        return this->_container.empty();
    }


    size_type size() const
    {
        return this->_container.size();
    }

     value_type& top()
     {
         value_type &ret = this->_container[this->_container.size() -1 ];
        return ret;
     }

     const value_type& top() const
     {
        const value_type &ret = this->_container[this->_container.size() -1];
        return ret;
     }
    void push (const value_type& val)
    {
        this->_container.push_back(val);
    }
    void pop()
    {
        this->_container.pop_back();
    }


            // template <class T1, class C>
            friend  bool operator== (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
            {
                        return lhs._container == rhs._container;
            }
            // template <class T1, class C>
            friend bool operator!= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
            {
                        return lhs._container != rhs._container;
            }
            // template <class T1, class C>
            friend  bool operator<  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
            {
                        return lhs._container < rhs._container;
            }
            // template <class T1, class C>
            friend bool operator<= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
            {
                        return lhs._container <= rhs._container;
            }
            // template <class T1, class C>
            friend bool operator>  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
            {
                        return lhs._container > rhs._container;
            }
            // template <class T1, class C>
            friend bool operator>= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
                        return lhs._container >= rhs._container;
            }

    protected:
container_type  _container;
};        
}