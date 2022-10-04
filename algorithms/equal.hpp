/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:23:03 by isfernan          #+#    #+#             */
/*   Updated: 2022/10/04 11:38:22 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

/*
	TEST WHETHER THE ELEMENTS IN TWO RANGES ARE EQUAL (function template)
	Compares the elements in the range [first1,last1) with those in the range beginning
	at first2, and returns true if all of the elements in both ranges match.
	The elements are compared using operator== (or pred, in version (2)).
*/

namespace ft{
	
template <typename InputIterator1, typename InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	while (first1 != last1) 
	{
		if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
			return false;
		++first1;
		++first2;
	}
	return true;
}
	
}

#endif