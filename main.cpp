/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:49 by isfernan          #+#    #+#             */
/*   Updated: 2022/10/27 18:27:44 by isfernan         ###   ########.fr       */
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


int		main(void)
{
	const int size = 5;
	ft::vector<int> vct(size);
	ft::vector<int>::iterator it_ = vct.begin();
	ft::vector<int>::reverse_iterator it(it_);

	for (int i = 0; i < size; ++i)
		vct[i] = (i + 1) * 5;
	//printSize(vct);

	std::cout << (it_ == it.base()) << std::endl;
	std::cout << (it_ == (it + 3).base()) << std::endl;

	std::cout << *(it.base() + 1) << std::endl;
	std::cout << *(it - 3) << std::endl;
	std::cout << *(it - 3).base() << std::endl;
	it -= 3;
	std::cout << *it.base() << std::endl;

	std::cout << "TEST OFFSET" << std::endl;
	std::cout << *(it) << std::endl;
	std::cout << *(it).base() << std::endl;
	std::cout << *(it - 0) << std::endl;
	std::cout << *(it - 0).base() << std::endl;
	std::cout << *(it - 1).base() << std::endl;

	return (0);
}

    // ft::vector<int>::iterator it;       // Call to first constructor
    // ft::vector<int>::iterator it2;      // Call to first constructor
    // ft::vector<int>::iterator it3;      // Call to first constructor

    
    // it = myvector.begin(); // begin() makes a call to second constructor
    // std::cout << *it[1] << std::endl;
    // it++; // operator++(int) makes a call to third constructor
