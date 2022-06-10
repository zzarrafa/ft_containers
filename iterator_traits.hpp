/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:09:22 by zzarrafa          #+#    #+#             */
/*   Updated: 2022/03/01 12:17:45 by zzarrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <iterator>


namespace ft
{
	template<class Iterator>
		struct iterator_traits{
			typedef typename Iterator::difference_type difference_type;
			typedef typename Iterator::value_type	  value_type;
			typedef typename Iterator::pointer			pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category iterator_category;
		};
}

