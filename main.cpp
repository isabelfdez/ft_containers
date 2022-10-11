/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:49 by isfernan          #+#    #+#             */
/*   Updated: 2022/10/11 14:41:24 by isfernan         ###   ########.fr       */
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
	std::vector<int> v;
	std::vector<int> v2;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);

	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(50);
	v2.push_back(60);
	v2.push_back(70);
	v2.push_back(80);


	std::vector<int>::iterator it2 = v.begin() + 4;
	std::vector<int>::iterator it3 = v2.begin();
	std::vector<int>::iterator it4 = v2.begin() + 3;
	
	std::vector<int>::const_iterator it = v.begin();

	std::cout << *it2 << std::endl;


	std::cout << *it3  << " " << *it4 << std::endl;
	
	v.insert(it2, it3, it4);
	std::cout << *it3  << " " << *it4 << std::endl;
	print_vector_std(v);

	std::cout << *it2 << std::endl;

	//v.insert(it2, it3, it4);
	//std::cout << *it3  << " " << *it4 << std::endl;
	//print_vector_std(v);

	//v.erase(it);
	//print_vector(v);

    //std::cout << it2[v.size()] << std::endl;
    
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
