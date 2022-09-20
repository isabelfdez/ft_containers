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
    ft::vector<int> v;
    
    v.push_back(10);
    std::cout << v.capacity() << std::endl;
    v.push_back(10);
    std::cout << v.capacity() << std::endl;
    v.push_back(10);
    std::cout << v.capacity() << std::endl;
    v.push_back(10);
    std::cout << v.capacity() << std::endl;
    v.push_back(10);
    

    return (0);
}