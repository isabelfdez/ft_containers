/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:41:46 by isfernan          #+#    #+#             */
/*   Updated: 2022/10/03 15:47:05 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

/*
	The type T is enabled as member type enable_if::type if Cond is true.
	Otherwise, enable_if::type is not defined.

	This is useful to hide signatures on compile time when a particular condition
	is not met, since in this case, the member enable_if::type will not be defined
	and attempting to compile using it should fail.

*/

namespace ft{

template <bool Cond, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> { typedef T type; };
    
}

/*
	Some examples on how to use it:
	1. The return type (bool) is only valid if T is an integral type:

	template <class T>
	typename std::enable_if<std::is_integral<T>::value,bool>::type
	is_odd (T i) {return bool(i%2);}
*/

#endif