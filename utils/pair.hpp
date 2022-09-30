/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:15:29 by isfernan          #+#    #+#             */
/*   Updated: 2022/09/30 14:25:34 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

template <typename T1, class T2>
struct pair
{
	pair(void) { }
	pair(const T1& a, const T2& b) : first(a), second(b) { }
	
	T1	first;
	T2	second;
};

}

#endif