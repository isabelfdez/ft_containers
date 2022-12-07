/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:16:12 by isfernan          #+#    #+#             */
/*   Updated: 2022/12/07 15:38:50 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSTNODE_HPP
# define BSTNODE_HPP

# include <iostream>

namespace ft{

// Aqui T es un par clave valor, y Compare el algoritmo que usaremos para comparar

template <typename T, typename Compare, typename Alloc>
class BSTNode
{
	public:

		typedef T													value_type;
		typedef Compare												key_compare;
		//typedef Alloc				allocator_type;
		typedef typename Alloc::template rebind<BSTNode>::other		allocator_type;
		typedef size_t												size_type;

		value_type					data;
		BSTNode						*left;
		BSTNode						*right;
		BSTNode						*parent;

		private:
			allocator_type			_alloc;
			key_compare				_comp;
			
			BSTNode*				min_node(BSTNode *node)
			{
				if (node->left)
					min_node(node->left);
				else if (node->right)
					min_node(node->right);
				return (node);
			}
	
		public:
		// Constructors & Destructor
			explicit BSTNode(value_type d = value_type(), const allocator_type& alloc = allocator_type(), 
					const key_compare& comp = key_compare()): data(d), _alloc(alloc), _comp(comp)
			{
				this->left = 0;
				this->right = 0;
				this->parent = 0;
				return ;
			}

			~BSTNode(void) {}
	
			// BSTNode(BSTNode const& copy)
			// {
			// 	std::cout << "copy constructor" << std::endl;
			// 	*this = copy;
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
			size_type		max_size(void) const { return (this->_alloc.max_size()); }
	
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
				else if (this->_comp(root->data.first, data.first))
					root->right = deleteNode(root->right, data);
				else if (this->_comp(data.first, root->data.first))
					root->left = deleteNode(root->left, data);
				else
				{
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
						temp = min_node(root->right);
						root->data = temp->data;
						deleteNode(temp, temp->data);					
					}
				}
				return temp;
			}
	
			// Clean
			void			clean(BSTNode** root)
			{
				if (!(*root))
					return ;
				if ((*root)->left)
					clean(&((*root)->left));
				if ((*root)->right)
					clean(&((*root)->right));
				(*root)->left = 0;
				(*root)->right = 0;
				this->_alloc.destroy(*root);
				this->_alloc.deallocate(*root, 1);
				*root = 0;
				return ;
			}
};



}

#endif