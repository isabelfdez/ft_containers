/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:49 by isfernan          #+#    #+#             */
/*   Updated: 2022/09/20 15:32:46 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

int main(void)
{
    //ft::vector<int> v;
    //
    //v.push_back(10);
    //std::cout << v.size() << " " << v.capacity() << std::endl;
    //v.push_back(20);
    //std::cout << v.size() << " " << v.capacity() << std::endl;
    //v.push_back(30);
    //std::cout << v.size() << " " << v.capacity() << std::endl;
    //v.push_back(40);
    //std::cout << v.size() << " " << v.capacity() << std::endl;
    //v.push_back(50);
    //std::cout << v.size() << " " << v.capacity() << std::endl;
    //std::cout << v[0] << std::endl;
    //std::cout << v[1] << std::endl;   
    //std::cout << v[2] << std::endl;
    //std::cout << v[3] << std::endl;
    //std::cout << v[4] << std::endl;
    //std::cout << v[5] << std::endl;
	//std::cout << v.size() << std::endl;
//
    //v.pop_back();
    //std::cout << v[0] << std::endl;
    //std::cout << v[1] << std::endl;   
    //std::cout << v[2] << std::endl;
    //std::cout << v[3] << std::endl;
    //std::cout << v[4] << std::endl;
	//std::cout << v[5] << std::endl;
	//std::cout << v.size() << std::endl;
	//v.push_back(55);
	//std::cout << v[0] << std::endl;
    //std::cout << v[1] << std::endl;   
    //std::cout << v[2] << std::endl;
    //std::cout << v[3] << std::endl;
    //std::cout << v[4] << std::endl;
	//std::cout << v[5] << std::endl;
	//std::cout << v.size() << std::endl;
    
    ft::vector<int *> v;
    
    int *a;
    int *b;
    a = (int *)malloc(sizeof(int));
    b = (int *)malloc(sizeof(int));
    *a = 10;
    *b = 30;


    
    v.push_back(a);
    std::cout << v.size() << " " << v.capacity() << std::endl;
    v.push_back(b);
    std::cout << v.size() << " " << v.capacity() << std::endl;
    std::cout << *v[0] << std::endl;
    std::cout << *v[1] << std::endl;   
    v.pop_back();
    std::cout << v.size() << " " << v.capacity() << std::endl;

    std::cout << *v[0] << std::endl;
    std::cout << *v[1] << std::endl; 
    int *c;
    c = (int *)malloc(sizeof(int));
    *c = 42;
    v.push_back(c);
    std::cout << v.size() << " " << v.capacity() << std::endl;
    std::cout << *v[0] << std::endl;
    std::cout << *v[1] << std::endl;

	//v.push_back(55);
	//std::cout << v.size() << std::endl;
	//std::cout << v[0] << std::endl;
    //std::cout << v[1] << std::endl;   
    //std::cout << v[2] << std::endl;
    //std::cout << v[3] << std::endl;
    //std::cout << v[4] << std::endl;
	//std::cout << v[5] << std::endl;
	//std::cout << v.size() << std::endl;
    std::cout << "-----CLEAR-----" << std::endl;
    v.clear();
    std::cout << v.size() << " " << v.capacity() << std::endl;
    std::cout << *v[0] << std::endl;
    std::cout << *v[1] << std::endl;
    system("leaks a.out");

    return (0);
}