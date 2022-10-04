/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:49:31 by isfernan          #+#    #+#             */
/*   Updated: 2022/10/04 11:35:11 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft{

/*	
	(class template)
	Static data members are class members that are declared using static keywords.
	A static member has certain special characteristics. These are:

	1)	Only one copy of that member is created for the entire class and is shared
		by all the objects of that class, no matter how many objects are created.
	2)	It is initialized before any object of this class is being created, even
		before main starts.
	3)	It is visible only within the class, but its lifetime is the entire program.
*/

template <typename T>
struct is_integral { const static bool	value = false; };

// Specializations

template<>
struct is_integral<bool> {const static bool value = true;};
template<>
struct is_integral<char> {const static bool value = true;};
template<>
struct is_integral<char16_t> {const static bool value = true;};
template<>
struct is_integral<char32_t> {const static bool value = true;};
template<>
struct is_integral<wchar_t> {const static bool value = true;};
template<>
struct is_integral<short> {const static bool value = true;};
template<>
struct is_integral<int> {const static bool value = true;};
template<>
struct is_integral<long> {const static bool value = true;};
template<>
struct is_integral<long long> {const static bool value = true;};

}

#endif