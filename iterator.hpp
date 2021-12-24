/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:42:00 by zzarrafa          #+#    #+#             */
/*   Updated: 2021/12/08 20:43:41 by zzarrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <iterator>

template< class T >
class iterator_traits
{
    private:
    Iter ite;
    public:
    typedef Iter iterator_type;
    typedef typename Iter::pointer pointer;
  typedef typename Iter::reference reference;
  typedef typename Iter::size_type size_type;
  typedef typename Iter::difference_type difference_type;
  typedef typename Iter::iterator_category iterator_category;
};