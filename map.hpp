/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:55:18 by isfernan          #+#    #+#             */
/*   Updated: 2022/11/18 17:32:00 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "utils/pair.hpp"
# include "utils/BSTNode.hpp"

namespace ft {

template <typename Key, typename T, typename Compare = std::less<Key>,
		typename Alloc = std::allocator<ft::pair<const Key, T> > >
class map
{
	public:
	// Redefinition of member types
	typedef Key												key_type;
	typedef T												mapped_type;
	typedef Compare											key_compare;
	typedef Alloc											allocator_type;
	typedef ft::pair<const key_type,mapped_type>			value_type;
	typedef typename allocator_type::pointer				pointer;
	typedef typename allocator_type::const_pointer			const_pointer;
	typedef typename allocator_type::reference				reference;
	typedef typename allocator_type::const_reference		const_reference;
	
};


}


#endif