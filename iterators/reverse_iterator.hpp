/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:12:15 by isfernan          #+#    #+#             */
/*   Updated: 2022/10/27 18:26:40 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {

template <typename Iterator>
class reverse_iterator
{
	public:
    	typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
        typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
    	typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
    	typedef typename ft::iterator_traits<Iterator>::reference			reference;
    	typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;    //using difference_type = typename std::iterator<std::random_access_iterator_tag, Type>::difference_type;
		typedef Iterator													iterator_type;
    
        // Constructors
        reverse_iterator() : _it(NULL) { /*std::cout << "First constructor called" << std::endl;*/ }
        explicit reverse_iterator (iterator_type it) : _it(it) { /*std::cout << "Second constructor called" << std::endl;*/ }
		template <typename Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it) : _it(rev_it.base()) { };

		// Deference operators
        reference						operator*() const 
		{
			iterator_type tmp = _it;
			--tmp;
			return *tmp;
		}
		pointer							operator->() const {return &(operator*());}
		reference						operator[](difference_type n) const {return *(_it - n - 1);}
		
		// Increment & decrement operators
        reverse_iterator&				operator++()
		{
			--_it;
			return *this;
		};
		reverse_iterator				operator++(int)
		{
			reverse_iterator temp = *this;
			--_it;
			return temp;
		};

        reverse_iterator&				operator--()
		{
			++_it;
			return *this;
		};
		reverse_iterator				operator--(int)
		{
			reverse_iterator temp = *this;
			++_it;
			return temp;
		};

		// Arithmetic operators
		reverse_iterator				operator+(difference_type n) const { return (_it + n); }
		reverse_iterator				operator-(difference_type n) const { return (_it - n); }
		
		// Assignment operators
		reverse_iterator&				operator+= (difference_type n) { _it += n; return (*this); }
		reverse_iterator&				operator-= (difference_type n) { _it -= n; return (*this); }

		// Getter
		iterator_type					base() const { return(_it); }
    private:
        iterator_type  					_it;
};

template <typename Iterator>
bool operator== (const reverse_iterator<Iterator>& lhs,
const reverse_iterator<Iterator>& rhs){
	return (lhs.base() == rhs.base());
}

template <typename Iterator>
bool operator!= (const reverse_iterator<Iterator>& lhs,
const reverse_iterator<Iterator>& rhs){
	return (lhs.base() != rhs.base());
}

template <typename Iterator>
bool operator<  (const reverse_iterator<Iterator>& lhs,
const reverse_iterator<Iterator>& rhs){
	return (lhs.base() > rhs.base());
}

template <typename Iterator>
bool operator<= (const reverse_iterator<Iterator>& lhs,
const reverse_iterator<Iterator>& rhs){
	return (lhs.base() >= rhs.base());
}

template <typename Iterator>
bool operator> (const reverse_iterator<Iterator>& lhs,
const reverse_iterator<Iterator>& rhs){
	return (lhs.base() < rhs.base());
}

template <typename Iterator>
bool operator>= (const reverse_iterator<Iterator>& lhs,
const reverse_iterator<Iterator>& rhs){
	return (lhs.base() <= rhs.base());
}

}

#endif