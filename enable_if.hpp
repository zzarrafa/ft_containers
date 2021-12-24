/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:29:48 by zzarrafa          #+#    #+#             */
/*   Updated: 2021/12/22 15:51:50 by zzarrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <iterator>
namespace ft{
template< class T >
struct is_integral{const static bool value=false;};

template<>
struct is_integral<int>{const static bool value =  true;};

template<>
struct is_integral<bool>{const static bool value =  true;};

template<>
struct is_integral<float>{const static bool value =  true;};

template<>
struct is_integral<char>{const static bool value =  true;};

template<>
struct is_integral<char16_t>{const static bool value =  true;};
template<>
struct is_integral<char32_t>{const static bool value =  true;};
template<>
struct is_integral<wchar_t>{const static bool value =  true;};
template<>
struct is_integral<signed char>{const static bool value =  true;};
template<>
struct is_integral<short int>{const static bool value =  true;};
template<>
struct is_integral<long int>{const static bool value =  true;};

template<>
struct is_integral<unsigned char>{const static bool value =  true;};
template<>
struct is_integral<unsigned short int>{const static bool value =  true;};

template<>
struct is_integral<unsigned int>{const static bool value =  true;};


template<>
struct is_integral<unsigned long int>{const static bool value =  true;};

template<>
struct is_integral<unsigned long long int>{const static bool value =  true;};

template <class T>
struct is_sample_type : std::integral_constant <
    bool,
    (ft::is_integral<T>::value)> {};

template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };
};
