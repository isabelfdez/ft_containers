/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:41:46 by isfernan          #+#    #+#             */
/*   Updated: 2022/10/04 11:34:21 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

/*
	ENABLE TYPE IF CONDITION IS MET (class template)

	The type T is enabled as member type enable_if::type if Cond is true.
	Otherwise, enable_if::type is not defined.

	This is useful to hide signatures on compile time when a particular condition
	is not met, since in this case, the member enable_if::type will not be defined
	and attempting to compile using it should fail.

*/

namespace ft{

template <bool Cond, typename T = void>
struct enable_if {};

// Specialization

template <typename T>
struct enable_if<true, T> { typedef T type; };
    
}

/*
	Some examples on how to use it:
	1) The return type (bool) is only valid if T is an integral type:

	template <class T>
	typename std::enable_if<std::is_integral<T>::value,bool>::type
	is_odd (T i) {return bool(i%2);}
	
	2) The second template argument is only valid if T is an integral type:
	template < class T,
           class = typename std::enable_if<std::is_integral<T>::value>::type>
	bool is_even (T i) {return !bool(i%2);}

	int main() 
	{

  		short int i = 1;    // code does not compile if type of i is not integral

		std::cout << std::boolalpha;
		std::cout << "i is odd: " << is_odd(i) << std::endl;
		std::cout << "i is even: " << is_even(i) << std::endl;

		return 0;
	}
	Output:
	i is odd: true
	i is even: false

*/

#endif