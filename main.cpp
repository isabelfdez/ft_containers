/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:49 by isfernan          #+#    #+#             */
/*   Updated: 2022/10/28 14:23:02 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vector.hpp"
# include <vector>
# include <iostream>
# include <list>

# define TESTED_NAMESPACE   ft
# define TESTED_TYPE        int
# define T_SIZE_TYPE        typename TESTED_NAMESPACE::vector<T>::size_type


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


template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}


int		main(void)
{
	std::list<TESTED_TYPE> lst;
	std::list<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	printSize(vct);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	printSize(vct);

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	printSize(vct);
	return (0);
}

// int main()
// {
//     ft::vector<int> v1;

//     //v1.push_back(30);
    
//     v1.insert(v1.begin(), 10, 88);
//     print_vector(v1);
//     ft::vector<int> v2(v1.begin(), v1.begin() + 3);
//     print_vector(v2);
    
    
// }


// int		main(void)
// {
	// std::list<TESTED_TYPE> lst;
	// std::list<TESTED_TYPE>::iterator lst_it;
	// for (int i = 1; i < 5; ++i)
		// lst.push_back(i * 3);
// 
	// TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	// printSize(vct);
// 
	// lst_it = lst.begin();
	// for (int i = 1; lst_it != lst.end(); ++i)
		// *lst_it++ = i * 5;
	// vct.assign(lst.begin(), lst.end());
	// printSize(vct);
// 
	// vct.insert(vct.end(), lst.rbegin(), lst.rend());
	// printSize(vct);
	// return (0);
// }
