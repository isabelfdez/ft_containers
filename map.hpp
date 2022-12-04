/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:55:18 by isfernan          #+#    #+#             */
/*   Updated: 2022/12/04 13:16:50 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "utils/pair.hpp"
# include "utils/BSTNode.hpp"
# include "iterators/BIterator.hpp"

namespace ft {

template <typename Key, typename T, typename Compare = std::less<Key>,
		typename Alloc = std::allocator<ft::pair<const Key, T> > >
class map
{
	public:
	// Redefinition of member types
		typedef BSTNode<ft::pair<Key, T>, Compare, Alloc>		BST;
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef Compare											key_compare;
		typedef Alloc											allocator_type;
		typedef ft::pair<const key_type, mapped_type>			value_type;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
    	typedef typename allocator_type::size_type				size_type;
		typedef BIterator<*BST, value_type>						iterator;
		typedef BIterator<const *BST, const value_type>			const_iterator;
	
	private:
		size_type		_size;
		BST				_Tree;
		BST*			_root;	// El "principio" de Tree
		BST*			_end; 	// El "final" de Tree
		size_type		_size;
		key_compare		_comp;
		allocator_type	_alloc;
	
	public:
		explicit map(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
		{
			this->_root = 0;
			this->_end = 0;
			//this->_end = this->_Tree.insert(this->_end, value_type());
			this->_size = 0;
			this->_comp = comp;
			this->_alloc = alloc;
			return ;
		}

		ft::pair<iterator, bool>	insert(const value_type& val)
		{
			BTree*	comp;

			comp = 0;
			if (this->_size > 0)
				comp = this->_Tree.search(this->_root, val);
			if (comp)
				return (ft::pair<iterator, bool>(iterator(comp), false));
			this->_size += 1;
			this->_root = this->_Tree.insert(this->_root, val);
			while (this->_root->parent && this->_root->parent->parent)
				this->_root = this->_root->parent;
			if (this->_size == 1)
			{
				this->_end->left = this->_root;
				this->_root->parent = this->_end;
			}
			comp = this->_Tree.search(this->_root, val);
			return (ft::pair<iterator, bool>(iterator(comp), true));
		}
		
		iterator					insert(iterator position, const value_type& val)
		{
			BTree*	comp;

			(void)position;
			comp = 0;
			if (this->_size > 0)
				comp = this->_Tree.search(this->_root, val);
			if (comp)
				return (ft::pair<iterator, bool>(iterator(comp), false));
			this->_size += 1;
			this->_root = this->_Tree.insert(this->_root, val);
			while (this->_root->parent && this->_root->parent->parent)
				this->_root = this->_root->parent;
			if (this->_size == 1)
			{
				this->_end->left = this->_root;
				this->_root->parent = this->_end;
			}
			comp = this->_Tree.search(this->_root, val);
			return (ft::pair<iterator, bool>(iterator(comp), true));
		}

		template <typename InputIterator>
		void						insert(InputIterator first, InputIterator last)
		{
			BTree*		comp;
			size_type	init;

			init = this->_size;
			while (first != last)
			{
				comp = this->_Tree.search(this->_root, *first);
				if (!comp)
				{
					this->_size += 1;
					this->_root = this->_Tree.insert(this->_root, *first);
					while (this->_root->parent && this->_root->parent->parent)
						this->_root = this->_root->parent;
				}
				first++;
			}
			if (init == 0 && this->_size > 0)
			{
				this->_end->left = this->_root;
				this->_root->parent = this->_end;
			}
			return ;
		}

	
	// map_iterate(BST* root)
	// {
		
	// }

	// BST* Leftmost(BST* node)
	// 	{
	// 	    if (node == nullptr)
	// 	        return nullptr;
	// 	    while (node->left != nullptr)
	// 	        node = node->left;
	// 	    return node;
	// 	}
		
	// 	// Start iterating from a root node
	// 	BST* First(BST* root)
	// 	{
	// 	    return Leftmost(root);
	// 	}
		
	// 	// The iteration is current at node.  Return the next node
	// 	// in value order.
	// 	BST* Next(BST* node)
	// 	{
	// 	    // Make sure that the caller hasn't failed to stop.
	// 	    assert(node != nullptr);
		
	// 	    // If we have a right subtree we must iterate over it,
	// 	    // starting at its leftmost (minimal) node.
		
	// 	    if (node->right != nullptr)
	// 	        return Leftmost(node->right);
		
	// 	    // Otherwise we must go up the tree
		
	// 	    BST* parent = node->parent;
	// 	    if (parent == nullptr)
	// 	        return nullptr;
		
	// 	    // A node comes immediately after its left subtree
		
	// 	    if (node == parent->left)
	// 	        return parent;
		
	// 	    // This must be the right subtree!
	// 	    assert(node == parent->right);
		
	// 	    // In which case we need to go up again, looking for a node that is
	// 	    // its parent's left child.
		
	// 	    while (parent != nullptr && node != parent->left)
	// 	    {
	// 	        node = parent;
	// 	        parent = node->parent;
	// 	    }
		
	// 	    // We should be at a left child!
	// 	    assert(parent == nullptr || node == parent->left);
		
	// 	    // And, as we know, a node comes immediately after its left subtree
		
	// 	    return parent;
	// 	}
};


}


#endif