/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BIterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:14:30 by isfernan          #+#    #+#             */
/*   Updated: 2022/11/18 18:02:12 by isfernan         ###   ########.fr       */
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
        node_ptr    _node;
        node_ptr    _end;
        node_ptr    _beginning;
        
    public:
        BIterator(node_ptr node = 0) : _node(node)
        {
            node_ptr	tmp(node);

			if (node && (tmp || tmp == this->_end))
			{
				while (tmp->parent && tmp->parent->parent)
					tmp = tmp->parent;
				while (tmp->left)
					tmp = tmp->left;
				this->_beg = tmp;
				tmp = node;
				while (tmp->parent)
					tmp = tmp->parent;
				this->_end = tmp;
			}
			else
			{
				this->_beg = 0;
				this->_end = 0;
			}
			return ;
        }
    // Constructors & destructor
        
};


}



#endif