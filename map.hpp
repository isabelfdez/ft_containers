/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:55:18 by isfernan          #+#    #+#             */
/*   Updated: 2022/11/22 16:31:31 by isfernan         ###   ########.fr       */
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
	typedef BSTree<ft::pair<Key, T>, Compare, Alloc>		BST;
	typedef Key												key_type;
	typedef T												mapped_type;
	typedef Compare											key_compare;
	typedef Alloc											allocator_type;
	typedef ft::pair<const key_type, mapped_type>			value_type;
	typedef typename allocator_type::pointer				pointer;
	typedef typename allocator_type::const_pointer			const_pointer;
	typedef typename allocator_type::reference				reference;
	typedef typename allocator_type::const_reference		const_reference;
	typedef BIterator<*BST, value_type>						iterator;
	typedef BIterator<const *BST, const value_type>			const_iterator;
	
	insert(BST* root, ft::pair<Key, T> hola)
	{
		
	}
	
	map_iterate(BST* root)
	{
		
	}

	BST* Leftmost(BST* node)
		{
		    if (node == nullptr)
		        return nullptr;
		    while (node->left != nullptr)
		        node = node->left;
		    return node;
		}
		
		// Start iterating from a root node
		BST* First(BST* root)
		{
		    return Leftmost(root);
		}
		
		// The iteration is current at node.  Return the next node
		// in value order.
		BST* Next(BST* node)
		{
		    // Make sure that the caller hasn't failed to stop.
		    assert(node != nullptr);
		
		    // If we have a right subtree we must iterate over it,
		    // starting at its leftmost (minimal) node.
		
		    if (node->right != nullptr)
		        return Leftmost(node->right);
		
		    // Otherwise we must go up the tree
		
		    BST* parent = node->parent;
		    if (parent == nullptr)
		        return nullptr;
		
		    // A node comes immediately after its left subtree
		
		    if (node == parent->left)
		        return parent;
		
		    // This must be the right subtree!
		    assert(node == parent->right);
		
		    // In which case we need to go up again, looking for a node that is
		    // its parent's left child.
		
		    while (parent != nullptr && node != parent->left)
		    {
		        node = parent;
		        parent = node->parent;
		    }
		
		    // We should be at a left child!
		    assert(parent == nullptr || node == parent->left);
		
		    // And, as we know, a node comes immediately after its left subtree
		
		    return parent;
		}
};


}


#endif