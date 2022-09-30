/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:18:12 by isfernan          #+#    #+#             */
/*   Updated: 2022/09/30 11:02:01 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>

namespace ft {
/*
	These are empty types, used to distinguish different iterators.  The
	distinction is not made by what they contain, but simply by what they
	are.  Different underlying algorithms can then be used based on the
	different operations supported by different iterator types.
*/
//  Marking input iterators.
//struct input_iterator_tag {};
//  Marking output iterators.
//struct output_iterator_tag {};
// Forward iterators support a superset of input iterator operations.
//struct forward_iterator_tag : public input_iterator_tag {};
// Bidirectional iterators support a superset of forward iterator
// operations.
//struct bidirectional_iterator_tag : public forward_iterator_tag {};
// Random-access iterators support a superset of bidirectional iterator
// operations.
//struct random_access_iterator_tag : public bidirectional_iterator_tag {};


/*
	The iterator_traits class template declares traits for an iterator. It contains
	all the relevant information regarding an iterator.

	QUESTION: Why do we need an iterator_traits class if we can obtain these traits
	from the Iterator directly?
	ANSWER: Pointers into an array can be used as random access iterators. There
	needs to be some consistent way to get these types both for pointers (which
	obviously can't have the types declared as nested types, since only classes can
	have nested types) and for class-type iterators. The traits class template provides
	this consistent way.
*/

template <typename Iterator> // Iterator stands for the type of iterator
struct iterator_traits
{
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};

// Specialization for ordinary pointers so they can also be used as iterators

template <typename T>
struct iterator_traits<T*> 
{
    typedef ptrdiff_t                           	difference_type;
    typedef T                                   	value_type;
    typedef T*                                  	pointer;
    typedef T&                                  	reference;
    typedef std::random_access_iterator_tag     	iterator_category;
};

// Specialization for constant pointers so they can also be used as iterators

template <typename T>
struct iterator_traits<const T*> 
{
    typedef ptrdiff_t                           	difference_type;
    typedef T                                   	value_type;
    typedef const T*                            	pointer;
    typedef const T&                            	reference;
    typedef std::random_access_iterator_tag     	iterator_category;
};

// template <typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
// struct my_iterator 
// {
// 		typedef T         							value_type;
// 		typedef Distance  							difference_type;
// 		typedef Pointer   							pointer;
// 		typedef Reference 							reference;
// 		typedef Category  							iterator_category;
// };

}

#endif