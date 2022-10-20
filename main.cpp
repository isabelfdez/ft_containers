/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:49 by isfernan          #+#    #+#             */
/*   Updated: 2022/10/20 19:17:41 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vector.hpp"
# include <vector>
# include <iostream>

void    print_vector(ft::vector<int> v)
{
    ft::vector<int>::iterator beg = v.begin();
    ft::vector<int>::iterator end = v.end();
    std::cout << "Printing the vector: ";
    std::cout << "[ ";
    if (beg != end)
    {
        std::cout << *beg;
        beg += 1;
        
    }
    while (beg != end)
    {
        std::cout << ", " << *beg;
        beg++;
    }
    std::cout << " ]" << std::endl;
}

void    print_vector_std(std::vector<int> v)
{
    std::vector<int>::iterator beg = v.begin();
    std::vector<int>::iterator end = v.end();
    std::cout << "Printing the vector: ";
    std::cout << "[ ";
    if (beg != end)
    {
        std::cout << *beg;
        beg += 1;
        
    }
    while (beg != end)
    {
        std::cout << ", " << *beg;
        beg++;
    }
    std::cout << " ]" << std::endl;
}


int main(void)
{
	ft::vector<int> v1(3, 4);
	ft::vector<int> v2;

	v2 = v1;
	print_vector(v2);

}

    // ft::vector<int>::iterator it;       // Call to first constructor
    // ft::vector<int>::iterator it2;      // Call to first constructor
    // ft::vector<int>::iterator it3;      // Call to first constructor

    
    // it = myvector.begin(); // begin() makes a call to second constructor
    // std::cout << *it[1] << std::endl;
    // it++; // operator++(int) makes a call to third constructor
