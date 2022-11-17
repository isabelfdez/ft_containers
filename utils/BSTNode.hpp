/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:16:12 by isfernan          #+#    #+#             */
/*   Updated: 2022/11/17 20:22:34 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSTNODE_HPP
# define BSTNODE_HPP

# include <iostream>

namespace ft{

template <typename T, typename Compare, typename Alloc = std::allocator<Node<T> > >
class BSTNode
{
	public:

		typedef T					value_type;
		typedef Compare				key_compare;
		typedef Alloc				allocator_type;
		typedef size_t				size_type;

		value_type	data;
		BSTNode		*left;
		BSTNode		*right;
		BSTNode		*parent;

		private:
			key_compare				_comp;
			allocator_type			_alloc;
	
		public:
		// Constructors & Destructor
		BSTNode(value_type d = value_type(), const key_compare& comp = key_compare(), 
			const allocator_type& alloc = allocator_type()): _alloc(alloc), _comp(comp), data(d)
		{
			this->left = 0;
			this->right = 0;
			this->parent = 0;
			return ;
		}

		// BSTNode(BSTNode const& copy)
		// {
		// 	_alloc = copy._alloc;
		// 	_comp = copy._comp;
		// 	_size = copy._size;
		// 	copy_node(*this, copy.root);
		// }

		// operator=
		BSTNode			operator=(BSTNode const& copy)
		{
			if (this != &copy)
			{
				this->data = copy.data;
				this->left = copy.left;
				this->right = copy.right;
				this->parent = copy.parent;
				this->_comp = copy.key_comp();
				this->_alloc = copy.get_allocator();
			}
			return *this;
		}

		// Getters

		allocator_type	get_allocator(void) const { return (this->_alloc); 	}

		key_compare		key_comp(void) const { return (this->_comp); }

		// Insert
		// HE CAMBIADO DATA POR D, REVISAR SI ESTA BIEN
		BSTNode*&		insert(BSTNode *&root, value_type d)
		{
			if (!root)
			{
				root = this->_alloc.allocate(1);
				this->_alloc.construct(root, BSTNode(d));
				return (root);
			}
			else if (this->_comp(d.first, root->data.first))
			{
				root->left = insert(root->left, d);
				root->left->parent = root;
			}
			else if (d.first != root->data.first)
			{
				root->right = insert(root->right, d);
				root->right->parent = root;
			}
			return (root);
		}

		// Find
		BSTNode*		search(BSTNode *root, value_type d) const
		{
			if (!root || root->data.first == d.first)
				return (root);
			else if (this->_comp(d.first, root->data.first))
				search(root->left, d);
			return (search(root->right, d));
		}
		
		// Delete
		BSTNode*		deleteNode(BSTNode *root, value_type data)
		{
			BSTNode	*temp;
			// Case 0: no root
			if (!root)
				return (root);
			// Case 1: leaf node
			if (!root->right && !root->left)
			{
				this->_alloc.destroy(root);
				this->_alloc.deallocate(root, 1);
			}
			// Case 2: 1 left child
			if (!root->right)
			{
				temp = root->left;
				temp->parent = root->parent;
				this->_alloc.destroy(root);
				this->_alloc.deallocate(root, 1);
			}
			// Case 3: 1 right child
			if (!root->left)
			{
				temp = root->right;
				temp->parent = root->parent;
				this->_alloc.destroy(root);
				this->_alloc.deallocate(root, 1);
			}
			// Case 4: 2 children
			else
			{
				
			}
		}
};



}

#endif