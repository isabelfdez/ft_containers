/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:49 by isfernan          #+#    #+#             */
/*   Updated: 2022/09/30 14:03:18 by isfernan         ###   ########.fr       */
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
    // int n = 3;  // nth element to be found.
    // int i = 0;  // counter.
    it = myvector.begin();
    it2 = myvector.end();
    while (it != it2)
    {
        std::cout<< *it << std::endl;
        ++it;
    }
    std::cout<< (it == it2) << std::endl;
    //std::cout<< *it << std::endl; 
    //++it;
    //std::cout<< *it << std::endl;


    
    // now start at from the beginning
    // and keep iterating over the element till you find
    // nth element...or reach the end of vector.
    //  for(it = myvector.begin(); it != myvector.end(); it++,i++ )    {
    //      // found nth element..print and break.
    //      if(i == n) {
    //          std::cout<< *it << std::endl;  // prints d.
    //          break;
    //      }
    //  }
    
    // // other easier ways of doing the same.
    // // using operator[]
    // cout<<myvector[n]<<endl;  // prints d.
    
    // // using the at method
    // cout << myvector.at(n) << endl;  // prints d.
    //system("leaks a.out");

    return (0);
}