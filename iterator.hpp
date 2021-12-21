/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zineb <zineb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:42:00 by zzarrafa          #+#    #+#             */
/*   Updated: 2021/12/20 23:28:03 by zineb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <iterator>

template <class T>
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