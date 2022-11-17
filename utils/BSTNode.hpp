/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:16:12 by isfernan          #+#    #+#             */
/*   Updated: 2022/11/17 19:16:46 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSTNODE_HPP
# define BSTNODE_HPP

# include <iostream>

namespace ft{

template <typename T>
struct Node
{
	typedef T	value_type;

	

	Node(value_type const &src) : data(src) { }
	Node(value_type const &src, Node *l, Node *r, Node *p) : data(src), left(l), right(r), parent(p) { }
	Node(Node *l, Node *r, Node *p) : left(l), right(r), parent(p) { }
};

template <typename T, typename Compare, typename Alloc = std::allocator<Node<T> > >
class BSTNode
{
	public:

		typedef T					value_type;
		typedef Compare				key_compare;
		typedef Alloc				allocator_type;
		typedef size_t				size_type;
		typedef Node<value_type>	node;
		typedef Node				*Node_ptr;

		value_type	data;
		node		*left;
		node		*right;
		node		*parent;
	
		// Constructors & Destructor
		BSTNode(const key_compare& comp = key_compare(), 
			const allocator_type& alloc = allocator_type()): _alloc(alloc), _comp(comp)
		{
			_size = 0;
			_root = NULL;
		}

		BSTNode(BSTNode const& copy)
		{
			_alloc = copy._alloc;
			_comp = copy._comp;
			_size = copy._size;
			copy_node(*this, copy.root);
		}

		private:
			key_compare				_comp;
			allocator_type			_alloc;

		// operator=
		BSTNode operator=(BSTNode const& copy)
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