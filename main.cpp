/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:49 by isfernan          #+#    #+#             */
/*   Updated: 2022/09/29 19:37:39 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

int main(void)
{
    ft::vector<std::string> myvector;  // a vector of stings.
    // push some strings in the vector.
    myvector.push_back("a");
    myvector.push_back("b");
    myvector.push_back("c");
    myvector.push_back("d");
    
    
    ft::vector<std::string>::iterator it;  // declare an iterator to a vector of strings
    int n = 3;  // nth element to be found.
    int i = 0;  // counter.
    myvector.begin();
    
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
    system("leaks a.out");

    return (0);
}