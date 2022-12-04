/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:49 by isfernan          #+#    #+#             */
/*   Updated: 2022/12/04 18:35:13 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/BSTNode.hpp"
#include "utils/pair.hpp"

int main()
{
	ft::BSTNode<ft::pair<int, char>, std::less<int>, std::allocator<ft::pair<const int, char> > > *node = NULL;

	//ft::BSTNode<ft::pair<int, char>, std::less<int>, std::allocator<ft::pair<const int, char> > > *node2(node);

	ft::pair<int, char> pair = ft::make_pair<int, char>(3, 'c');
	node->insert(node, pair);
	//ft::BSTNode<ft::pair<int, char>, std::less<int>, std::allocator<ft::pair<const int, char> > > *searched = node->search(node, pair);
	
}