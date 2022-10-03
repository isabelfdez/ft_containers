/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:49 by isfernan          #+#    #+#             */
/*   Updated: 2022/10/03 15:21:53 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vector.hpp"
# include <vector>
# include <iostream>


int main(void)
{
    ft::vector<int> myvector;
    // ft::iterator_traits<std::vector<int>::iterator>::difference_type a;
    // ft::iterator_traits<std::allocator<int>::pointer>::difference_type b;
    // ft::iterator_traits<int *>::difference_type c;

    // ft::vector<std::string> myvector;  // a vector of stings.
    myvector.push_back(1);
    myvector.push_back(2);
    myvector.push_back(3);
    myvector.push_back(4);
    
    
    ft::vector<int>::iterator it;     
    ft::vector<int>::iterator it2;
    ft::vector<int>::iterator it3; 

    
    it = myvector.begin();
    std::cout << *it[1] << std::endl;
    it++;

    
    
    //system("leaks a.out");

    return (0);
}