/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:49 by isfernan          #+#    #+#             */
/*   Updated: 2022/10/06 15:03:57 by isfernan         ###   ########.fr       */
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
	ft::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);


	ft::vector<int>::iterator it = v.begin() + 1;
	ft::vector<int>::iterator it2 = v.begin();
	
	print_vector(v);
	v.erase(it);
	print_vector(v);
	//print_vector_std(v);
	//std::cout << v.size() << " " << v.capacity() << std::endl;
	//v.erase(it);
	//print_vector_std(v);
	//std::cout << v.size() << " " << v.capacity() << std::endl;
	
		
    






    
    
    

    

    
    
    //system("leaks a.out");

    return (0);
}

    // ft::vector<int>::iterator it;       // Call to first constructor
    // ft::vector<int>::iterator it2;      // Call to first constructor
    // ft::vector<int>::iterator it3;      // Call to first constructor

    
    // it = myvector.begin(); // begin() makes a call to second constructor
    // std::cout << *it[1] << std::endl;
    // it++; // operator++(int) makes a call to third constructor
