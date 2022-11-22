/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BIterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:14:30 by isfernan          #+#    #+#             */
/*   Updated: 2022/11/22 16:13:05 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITERATOR_HPP
# define BITERATOR_HPP

# include "iterator_traits.hpp"
# include "../utils/BSTNode.hpp"

namespace ft{

template <typename Node, typename T>

class BIterator
{
    public:
    // Redefinition of member types
        typedef std::bidirectional_iterator_tag						iterator_category;
		typedef typename ft::iterator_traits<Node>::value_type		node;
		typedef typename ft::iterator_traits<Node>::difference_type	difference_type;
		typedef typename ft::iterator_traits<Node>::pointer			node_ptr;
		typedef typename ft::iterator_traits<Node>::reference		node_ref;
		typedef T													value_type;
		typedef T*													pointer;
		typedef T&													reference;
        
    private:
        node_ptr	_node;
        node_ptr	_end;
        node_ptr	_beginning;

	public:
		BIterator(node_ptr node = 0) : _node(node) { }

		Iterate(node_ptr node)
		{
			node_ptr smallest = Leftmost(node);
			while (node)
			{
				std::cout << node->data << std::endl;
				node = Next(node);
			}
		}

	private:
		node_ptr Leftmost(node_ptr node)
		{
		    if (node == nullptr)
		        return nullptr;
		    while (node->left != nullptr)
		        node = node->left;
		    return node;
		}
		
		// Start iterating from a root node
		node_ptr First(node_ptr root)
		{
		    return Leftmost(root);
		}
		
		// The iteration is current at node.  Return the next node
		// in value order.
		node_ptr Next(node_ptr node)
		{
		    // Make sure that the caller hasn't failed to stop.
		    assert(node != nullptr);
		
		    // If we have a right subtree we must iterate over it,
		    // starting at its leftmost (minimal) node.
		
		    if (node->right != nullptr)
		        return Leftmost(node->right);
		
		    // Otherwise we must go up the tree
		
		    node_ptr* parent = node->parent;
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
		
    // Constructors & destructor
        // BIterator(node_ptr node = 0) : _node(node)
        // {
        //     node_ptr	tmp(node);

		// 	if (node && (tmp || tmp == this->_end))
		// 	{
		// 		while (tmp->parent && tmp->parent->parent)
		// 			tmp = tmp->parent;
		// 		while (tmp->left)
		// 			tmp = tmp->left;
		// 		this->_beg = tmp;
		// 		tmp = node;
		// 		while (tmp->parent)
		// 			tmp = tmp->parent;
		// 		this->_end = tmp;
		// 	}
		// 	else
		// 	{
		// 		this->_beg = 0;
		// 		this->_end = 0;
		// 	}
		// 	return ;
        // }
        
};


}



#endif