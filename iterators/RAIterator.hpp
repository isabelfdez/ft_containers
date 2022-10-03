/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAiterator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:07:17 by isfernan          #+#    #+#             */
/*   Updated: 2022/10/03 15:25:43 by isfernan         ###   ########.fr       */
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
        RAIterator() : _ptr(NULL) { std::cout << "First constructor called" << std::endl; }
        RAIterator(T src) : _ptr(src) { std::cout << "Second constructor called" << std::endl; }
        RAIterator(const RAIterator &src) : _ptr(src._ptr) { std::cout << "Third constructor called" << std::endl; }

		// Deference operators
        reference	operator*() const { return(*_ptr); }
		pointer		operator->() const { return(&(operator*())); }
        pointer     operator[](difference_type src) const { return (&(_ptr[src])); }
		
		// Increment & decrement operators
        RAIterator&	operator++() { ++_ptr; return (*this); }
		RAIterator	operator++(int)
		{
			RAIterator ret(*this);
			++_ptr;
			return ret;
		}

        RAIterator&	operator--() { --_ptr; return (*this); }
		RAIterator	operator--(int)
		{
			RAIterator ret(*this);
			--_ptr;
			return ret;
		}

		// Arithmetic operators
		RAIterator& operator+(const difference_type& n)  const { return (RAIterator(_ptr + n)); }
		//RAIterator& operator+(const RAIterator& it) { return (RAIterator(_ptr + it._ptr)); }

		RAIterator& operator-(const int& n) const { return (RAIterator(_ptr - n)); }
		//RAIterator& operator-(const RAIterator& it) { return (RAIterator(_ptr - it._ptr)); }

		// Assignment operators
		RAIterator&	operator=(const RAIterator &it) { _ptr = it._ptr; return (*this); }
		RAIterator&	operator+=(const difference_type& n) { _ptr+=n; return (*this); }

		// Relational operators
		bool		operator==(const RAIterator &it) const { return(_ptr == it._ptr); }
		bool		operator!=(const RAIterator &it) const { return(_ptr != it._ptr); }
		bool		operator>(const RAIterator &it) const { return(_ptr > it._ptr); }
		bool		operator<(const RAIterator &it) const { return(_ptr < it._ptr); }
		bool		operator>=(const RAIterator &it) const { return(_ptr >= it._ptr); }
		bool		operator<=(const RAIterator &it) const { return(_ptr <= it._ptr); }
    
    private:
        pointer  _ptr;
};

// template<typename T>
// class	VectorIterator : public ft::my_iterator<std::random_access_iterator_tag, T> 
// {
// 	public:
// 		typedef typename ft::iterator_traits<T>				iterator_traits;
// 		typedef typename iterator_traits::pointer			pointer;
// 		typedef typename iterator_traits::reference			reference;
// 		typedef typename iterator_traits::difference_type	difference_type;
// 		typedef pointer										iterator_type;

// 		VectorIterator(): _p(NULL) {}
// 		explicit VectorIterator(iterator_type x): _p(x) {}

// 		template<class U> 
// 		VectorIterator(const VectorIterator<U> &other) {
// 			this->_p = other.base();
// 		}

//		iterator_type	base() const { return (this->_p); }
//
//		reference	operator*() const { return (*this->_p); }
//		pointer		operator->() const { return (this->_p); }
//
//		reference	operator[](difference_type index) const { return (*(_p + index)); }
//
//		VectorIterator	&operator++() { ++_p; return (*this); }
//		VectorIterator	operator++(int) { VectorIterator tmp(*this); operator++(); return (tmp); }
//		VectorIterator	&operator+=(difference_type n) { this->_p += n; return (*this); }
//		VectorIterator	operator+(difference_type n) const { VectorIterator tmp(*this); tmp._p += n; return (tmp);}
//
//		VectorIterator	&operator--() { --_p; return (*this); }
//		VectorIterator	operator--(int) { VectorIterator tmp(*this); operator--(); return (tmp); }
//		VectorIterator	&operator-=(difference_type n) { this->_p -= n; return (*this); }
//		VectorIterator	operator-(difference_type n) const { VectorIterator tmp(*this); tmp._p -= n; return (tmp);}
//	private:
//		iterator_type	_p;
//};

//	template<class Iterator1, class Iterator2>
//	bool	operator==(const VectorIterator<Iterator1>& lhs, const VectorIterator<Iterator2>& rhs) {
//		return lhs.base() == rhs.base();
//	}
//
//	template<class Iterator1, class Iterator2>
//	bool	operator!=(const VectorIterator<Iterator1>& lhs, const VectorIterator<Iterator2>& rhs) {
//		return lhs.base() != rhs.base();
//	}
//
//	template<class Iterator1, class Iterator2>
//	bool	operator>(const VectorIterator<Iterator1>& lhs, const VectorIterator<Iterator2>& rhs) {
//		return lhs.base() > rhs.base();
//	}
//
//	template<class Iterator1, class Iterator2>
//	bool	operator>=(const VectorIterator<Iterator1>& lhs, const VectorIterator<Iterator2>& rhs) {
//		return lhs.base() >= rhs.base();
//	}
//
//	template<class Iterator1, class Iterator2>
//	bool	operator<(const VectorIterator<Iterator1>& lhs, const VectorIterator<Iterator2>& rhs) {
//		return lhs.base() < rhs.base();
//	}
//
//	template<class Iterator1, class Iterator2>
//	bool	operator<=(const VectorIterator<Iterator1>& lhs, const VectorIterator<Iterator2>& rhs) {
//		return lhs.base() <= rhs.base();
//	}
//
//	template<class Iterator>
//	VectorIterator<Iterator> operator+(typename VectorIterator<Iterator>::difference_type n, const VectorIterator<Iterator> &it) {
//		VectorIterator<Iterator>	tmp(it.base() + n);
//		return (tmp);
//	}
//
//	template<class Iterator, class Iterator2>
//	typename VectorIterator<Iterator>::difference_type operator-(const VectorIterator<Iterator>& lhs, const VectorIterator<Iterator2>& rhs) {
//		return (lhs.base() - rhs.base());
//	}
//
}

#endif