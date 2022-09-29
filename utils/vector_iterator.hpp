/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:07:17 by isfernan          #+#    #+#             */
/*   Updated: 2022/09/29 19:18:20 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "iterator.hpp"
# include <iostream>

namespace ft {

template<typename Type>
class VectorIterator : public std::iterator<std::random_access_iterator_tag, Type>
{
public:
	typedef typename std::iterator<std::random_access_iterator_tag, Type>::difference_type difference_type;
    //using difference_type = typename std::iterator<std::random_access_iterator_tag, Type>::difference_type;
    
    VectorIterator() : _ptr(nullptr) {}
    VectorIterator(Type* rhs) : _ptr(rhs) {}
    VectorIterator(const VectorIterator &rhs) : _ptr(rhs._ptr) {}
    /* inline VectorIterator& operator=(Type* rhs) {_ptr = rhs; return *this;} */
    /* inline VectorIterator& operator=(const VectorIterator &rhs) {_ptr = rhs._ptr; return *this;} */
    inline VectorIterator& operator+=(difference_type rhs) {_ptr += rhs; return *this;}
    inline VectorIterator& operator-=(difference_type rhs) {_ptr -= rhs; return *this;}
    inline Type& operator*() const {return *_ptr;}
    inline Type* operator->() const {return _ptr;}
    inline Type& operator[](difference_type rhs) const {return _ptr[rhs];}
    
    inline VectorIterator& operator++() {++_ptr; return *this;}
    inline VectorIterator& operator--() {--_ptr; return *this;}
    inline VectorIterator operator++(int) const {VectorIterator tmp(*this); ++_ptr; return tmp;}
    inline VectorIterator operator--(int) const {VectorIterator tmp(*this); --_ptr; return tmp;}
    /* inline VectorIterator operator+(const VectorIterator& rhs) {return VectorIterator(_ptr+rhs.ptr);} */
    inline difference_type operator-(const VectorIterator& rhs) const {return _ptr-rhs.ptr;}
    inline VectorIterator operator+(difference_type rhs) const {return VectorIterator(_ptr+rhs);}
    inline VectorIterator operator-(difference_type rhs) const {return VectorIterator(_ptr-rhs);}
    friend inline VectorIterator operator+(difference_type lhs, const VectorIterator& rhs) {return VectorIterator(lhs+rhs._ptr);}
    friend inline VectorIterator operator-(difference_type lhs, const VectorIterator& rhs) {return VectorIterator(lhs-rhs._ptr);}
    
    inline bool operator==(const VectorIterator& rhs) const {return _ptr == rhs._ptr;}
    inline bool operator!=(const VectorIterator& rhs) const {return _ptr != rhs._ptr;}
    inline bool operator>(const VectorIterator& rhs) const {return _ptr > rhs._ptr;}
    inline bool operator<(const VectorIterator& rhs) const {return _ptr < rhs._ptr;}
    inline bool operator>=(const VectorIterator& rhs) const {return _ptr >= rhs._ptr;}
    inline bool operator<=(const VectorIterator& rhs) const {return _ptr <= rhs._ptr;}
private:
    Type* _ptr;
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