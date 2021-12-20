/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:29:48 by zzarrafa          #+#    #+#             */
/*   Updated: 2021/12/20 18:46:13 by zzarrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <iterator>

template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };


template<typename> struct is_integral_base: std::false_type {};

template<> struct is_integral_base<bool>: std::true_type {};
template<> struct is_integral_base<int>: std::true_type {};
template<> struct is_integral_base<char16_t>: std::true_type {};
template<> struct is_integral_base<char32_t>: std::true_type {};
template<> struct is_integral_base<wchar_t>: std::true_type {};
template<> struct is_integral_base<short>: std::true_type {};
template<> struct is_integral_base<long>: std::true_type {};
// template<> struct is_integral_base<long long>: std::true_type {};
template<> struct is_integral_base<signed char>: std::true_type {};
// template<> struct is_integral_base<short int>: std::true_type {};
// template<> struct is_integral_base<long int>: std::true_type {};
template<> struct is_integral_base<long long int>: std::true_type {};
template<> struct is_integral_base<unsigned char>: std::true_type {};
template<> struct is_integral_base<unsigned short int>: std::true_type {};
template<> struct is_integral_base<unsigned long int>: std::true_type {};
template<> struct is_integral_base<unsigned long long int>: std::true_type {};



template<typename T> struct is_integral: is_integral_base<std::remove_cv<T> > {};