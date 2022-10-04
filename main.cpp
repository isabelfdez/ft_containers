/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:49 by isfernan          #+#    #+#             */
/*   Updated: 2022/10/04 13:43:52 by isfernan         ###   ########.fr       */
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


int main(void)
{
    ft::vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    
    ft::vector<int> v2;
    ft::vector<int>::iterator it = v.begin();
    ft::vector<int>::iterator it2 = v.end();
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);
    v2.push_back(60);
    v2.push_back(70);
    std::cout << "is_integral: " << ft::is_integral<ft::vector<int>::iterator>::value << std::endl;


    
    
    std::cout << v2.size() << " " << v2.capacity() << std::endl;
    v2.assign(it, it2);
    print_vector(v2);
    std::cout << v2.size() << std::endl;
    

    
    
    //system("leaks a.out");

    return (0);
}

    // ft::vector<int>::iterator it;       // Call to first constructor
    // ft::vector<int>::iterator it2;      // Call to first constructor
    // ft::vector<int>::iterator it3;      // Call to first constructor

    
    // it = myvector.begin(); // begin() makes a call to second constructor
    // std::cout << *it[1] << std::endl;
    // it++; // operator++(int) makes a call to third constructor
