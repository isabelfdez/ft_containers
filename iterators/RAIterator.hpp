/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAIterator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:07:17 by isfernan          #+#    #+#             */
/*   Updated: 2022/10/28 14:29:14 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAITERATOR_HPP
# define RAITERATOR_HPP

# include "iterator_traits.hpp"
# include <iostream>

namespace ft {

/* 
    QUESTION: What is T here?
    ANSWER: It is a pointer. All of the following lines are correct:

    ft::iterator_traits<std::vector<int>::iterator>::difference_type a;
    ft::iterator_traits<std::allocator<int>::pointer>::difference_type b;
    ft::iterator_traits<int *>::difference_type c;

    However, the following one is incorrect:
    
    ft::iterator_traits<int>::difference_type c;

    This class will always be instanciated with RAIterator<pointer>	(or const
    iterator).
*/

template<typename T> 
class RAIterator
{
    public:
    	typedef typename ft::iterator_traits<T>::difference_type	difference_type;
        typedef typename ft::iterator_traits<T>::value_type			value_type;
    	typedef typename ft::iterator_traits<T>::pointer			pointer;
    	typedef typename ft::iterator_traits<T>::reference			reference;
    	typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;    //using difference_type = typename std::iterator<std::random_access_iterator_tag, Type>::difference_type;
    
        // Constructors
        RAIterator() : _ptr(NULL) { /*std::cout << "First constructor called" << std::endl;*/ }
        RAIterator(T src) : _ptr(src) { /*std::cout << "Second constructor called" << std::endl;*/ }
        RAIterator(const RAIterator &src) : _ptr(src._ptr) { /*std::cout << "Third constructor called" << std::endl;*/ } // CHANGE
		template <typename S> // Needed to convert const iterator to iterator or viceversa
		RAIterator(const RAIterator<S> &other) { _ptr = other.base(); }

		// Deference operators
        reference				operator*() const { return(*_ptr); }
		pointer					operator->() const { return(&(operator*())); }
        reference				operator[](difference_type src) { return (_ptr[src]); }
		
		// Increment & decrement operators
        RAIterator&				operator++() { ++_ptr; return (*this); } // ++it
		RAIterator				operator++(int) // it++
		{
			RAIterator ret(*this);
			++_ptr;
			return ret;
		}

        RAIterator&				operator--() { --_ptr; return (*this); } // --it
		RAIterator				operator--(int) // it--
		{
			RAIterator ret(*this);
			--_ptr;
			return ret;
		}

		// Arithmetic operators
		RAIterator				operator+(const difference_type& n)  const { return (RAIterator(_ptr + n)); }
		friend RAIterator		operator+(const int& n, const RAIterator& it)  { return (RAIterator(it.base() + n)); }
		RAIterator				operator-(const int& n) const { return (RAIterator(_ptr - n)); }
		difference_type			operator-(const RAIterator& it) { return (_ptr - it._ptr); }
		// friend difference_type	operator-(const RAIterator& it1, const RAIterator& it2)
		// {
		// 	return (RAIterator(it.base() + n));
		// }

		// Assignment operators
		RAIterator&				operator=(const RAIterator &it) { _ptr = it._ptr; return (*this); }
		RAIterator&				operator=(RAIterator &it) { _ptr = it._ptr; return (*this); }
		RAIterator&				operator+=(const difference_type& n) { _ptr += n; return (*this); }
		RAIterator&				operator-=(const difference_type& n) { _ptr -= n; return (*this); }		
    
		// Getter
		pointer					base() const { return(_ptr); }
    private:
        pointer  				_ptr;
};

template<class Iterator1, class Iterator2>
bool	operator==(const RAIterator<Iterator1>& lhs, const RAIterator<Iterator2>& rhs)
{
	return lhs.base() == rhs.base();
}
template<class Iterator1, class Iterator2>
bool	operator!=(const RAIterator<Iterator1>& lhs, const RAIterator<Iterator2>& rhs)
{
	return lhs.base() != rhs.base();
}
template<class Iterator1, class Iterator2>
bool	operator>(const RAIterator<Iterator1>& lhs, const RAIterator<Iterator2>& rhs)
{
	return lhs.base() > rhs.base();
}
template<class Iterator1, class Iterator2>
bool	operator>=(const RAIterator<Iterator1>& lhs, const RAIterator<Iterator2>& rhs)
{
	return lhs.base() >= rhs.base();
}
template<class Iterator1, class Iterator2>
bool	operator<(const RAIterator<Iterator1>& lhs, const RAIterator<Iterator2>& rhs)
{
	return lhs.base() < rhs.base();
}
template<class Iterator1, class Iterator2>
bool	operator<=(const RAIterator<Iterator1>& lhs, const RAIterator<Iterator2>& rhs)
{
	return lhs.base() <= rhs.base();
}
// template<class Iterator>
// RAIterator<Iterator> operator+(typename RAIterator<Iterator>::difference_type n, const RAIterator<Iterator> &it) {
// 	RAIterator<Iterator>	tmp(it.base() + n);
// 	return (tmp);
// }
// template<class Iterator, class Iterator2>
// typename RAIterator<Iterator>::difference_type operator-(const RAIterator<Iterator>& lhs, const RAIterator<Iterator2>& rhs) {
// 	return (lhs.base() - rhs.base());
// }

}

#endif