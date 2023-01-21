/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:15:29 by isfernan          #+#    #+#             */
/*   Updated: 2023/01/21 18:05:21 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

template <typename T1, typename T2>
struct pair
{
	typedef T1		first_type;
	typedef T2		second_type;

	first_type		first;
	second_type		second;

	// Constructors
	// default (1): Constructs a pair object with its elements value-initialized.
	pair() : first(), second() { }
	// copy (2) (and implicit conversion): The object is initialized with the contents
	// of the pr pair object. The corresponding member of pr is passed to the constructor
	// of each of its members.	
	template<typename U, typename V>
	pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) { }
	// initialization (3): Member first is constructed with a and member second with b.
	pair(const first_type& a, const second_type& b) : first(a), second(b) { }
	
	// operator
	pair&			operator=(const pair& pr)
	{
		first = pr.first;
		second = pr.second;
		return (*this);
	}
};

template <typename T1, typename T2>
bool operator== (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return lhs.first == rhs.first && lhs.second == rhs.second; }

template <typename T1, typename T2>
bool operator!= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return !(lhs == rhs); }

template <typename T1, typename T2>
bool operator<  (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

template <typename T1, typename T2>
bool operator<= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return !(rhs < lhs); }

template <typename T1, typename T2>
bool operator>  (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return rhs < lhs; }

template <typename T1, typename T2>
bool operator>= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return !(lhs < rhs); }

template <typename T1,typename T2>
ft::pair<T1,T2> make_pair(T1 x, T2 y) { return ft::pair<T1, T2>(x, y); }

}

#endif