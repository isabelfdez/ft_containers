/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:16:12 by isfernan          #+#    #+#             */
/*   Updated: 2022/11/08 14:57:37 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSTREE_HPP
# define BSTREE_HPP

# include <iostream>

namespace ft{

template <typename T>
struct Node
{
	typedef T	value_type;

	value_type	data;
	Node		*left;
	Node		*right;
	Node		*parent;
};

template <typename T, typename Compare, typename Alloc = std::allocator<Node<T> > >
class BSTree
{
	typedef T					value_type;
	typedef Compare				key_compare;
	typedef Alloc				allocator_type;
	typedef size_t				size_type;
	typedef Node<value_type>	Node;
	typedef Node				*Node_ptr;
	
	// Constructors & Destructor
	BSTree(const key_compare& comp = key_compare(), 
		const allocator_type& alloc = allocator_type()): _alloc(alloc), _comp(comp)
	{
		_size = 0;
		_root = NULL;
	}

	BSTree(BSTree const& copy)
	{
		_alloc = copy._alloc;
		_comp = copy._comp;
		_size = copy._size;
		_deepCopy(*this, copy._root);
	}

	// operator=
	BSTree operator=(BSTree const& copy)
	{
		if (this != &copy)
		{
			_alloc = copy._alloc;
			_comp = copy._comp;
			_size = copy._size;
			_deepCopy(*this, copy._root);
		}
		return *this;
	}
};



}

#endif