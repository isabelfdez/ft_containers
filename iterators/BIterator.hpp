/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BIterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:14:30 by isfernan          #+#    #+#             */
/*   Updated: 2022/12/07 13:18:26 by isfernan         ###   ########.fr       */
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
        node_ptr	_beg;
        node_ptr	_end;

	public:
		BIterator(node_ptr node = 0) : _node(node)
		{
			node_ptr	tmp(node);

			if (node)
			{
				while (tmp->parent)
					tmp = tmp->parent;
				while (tmp->left)
					tmp = tmp->left;
				this->_beg = tmp;
				tmp = node;
				while (tmp->parent)
					tmp = tmp->parent;
				while (tmp->right)
					tmp = tmp->right;
				this->_end = tmp;
			}
			else
			{
				this->_beg = 0;
				this->_end = 0;
			}
			return ;
		}

		template < typename UNode, typename U >
		BIterator(const BIterator<UNode, U>& other)
			: _node(other.root()), _beg(other.begin()), _end(other.end())
		{
			return ;
		}

		/** Destructor **/
		~BIterator(void) {}

		BIterator&		operator=(const BIterator& other)
		{
			this->_node = other.root();
			this->_beg = other.begin();
			this->_end = other.end();
			return (*this);
		}

		/** Member Functions **/
		node_ptr		root(void) const { return (this->_node); }
		node_ptr		begin(void) const { return (this->_beg); }
		node_ptr		end(void) const { return (this->_end); }

		/** Member Functions **/
		reference		operator*(void) const { return (this->_node->data); }
		pointer			operator->(void) const { return (&(operator*())); }

		// BIterator&		operator++(void)
		// {
		// 	node_ptr	tmp(this->_node);

		// 	if (this->_node->right)
		// 	{
				
		// 	}
		// }
		BIterator&	operator++(void)
		{
			node_ptr	output;

			output = this->_node;
			if (output && output->right)
			{
				output = output->right;
				while (output->left)
					output = output->left;
			}
			else if (output != this->_end)
			{
				while (output->parent && output != output->parent->left)
					output = output->parent;
				output = output->parent;
			}
			this->_node = output;
			return (*this);
		}

		BIterator		operator++(int)
		{
			BIterator	output(*this);

			++(*this);
			return (output);
		}

		BIterator&		operator--(void)
		{
			node_ptr	output;

			output = this->_node;
			if (output->left)
			{
				output = output->left;
				while (output->right)
					output = output->right;
			}
			else if (output != this->_beg)
			{
				while (output->parent && output != output->parent->right)
					output = output->parent;
				output = output->parent;
			}
			this->_node = output;
			return (*this);
		}

		BIterator		operator--(int)
		{
			BIterator	output(*this);

			--(*this);
			return (output);
		}        
};

template < typename TNode, typename T, typename UNode, typename U >
bool	operator==(const BIterator<TNode, T>& lhs, const BIterator<UNode, U> rhs)
{
	return (lhs.root() == rhs.root());
}

template < typename TNode, typename T, typename UNode, typename U >
bool	operator!=(const BIterator<TNode, T>& lhs, const BIterator<UNode, U> rhs)
{
	return (lhs.root() != rhs.root());
}


}



#endif

// node_ptr	output;

			// output = this->_node;
			// if (output && output->right)
			// {
			// 	output = output->right;
			// 	while (output->left)
			// 		output = output->left;
			// }
			// else if (output != this->_end)
			// {
			// 	while (output->parent && output != output->parent->left)
			// 		output = output->parent;
			// 	output = output->parent;
			// }
			// this->_node = output;
			// return (*this);