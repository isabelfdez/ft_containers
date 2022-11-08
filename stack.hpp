/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:48:43 by isfernan          #+#    #+#             */
/*   Updated: 2022/11/08 12:54:48 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {

template <typename T, typename Container = ft::vector<T> >
class stack
{
	public:
		typedef	T			value_type;
		typedef	Container	container_type;
		typedef size_t		size_type;

		explicit stack(const container_type& ctnr = container_type()) : _ctnr(ctnr) { }

	protected:
		container_type		_ctnr;

	public: // Member functions in alphabetical order
		// empty
		bool				empty() const { return (this->_ctnr.size() == 0); }

		// pop
		void				pop() { this->_ctnr.pop_back(); }
		
		// push
		void				push(const value_type& val) { this->_ctnr.push_back(val); }

		// size
		size_type			size() const { return (this->_ctnr.size()); }

		//top
		value_type&			top() { return (this->_ctnr.back()); }
		const value_type&	top() const { return (this->_ctnr.back()); }

		// operators
		// template <typename T1, typename Cont>
		// friend bool			operator==(const stack<T1, Cont>& lhs, const stack<T1, Cont>& rhs)
		// {
		// 	return (lhs._ctnr == rhs._ctnr);
		// }
	
		// template <typename T1, typename Cont>
		// friend bool			operator<(const stack<T1, Cont>& lhs, const stack<T1, Cont>& rhs)
		// {
		// 	return (lhs._ctnr < rhs._ctnr);
		// }
		template <class A, class B>
		friend bool			operator==(const stack<A,B> &lhs, const stack<A,B> &rhs);
		template <class A, class B>
		friend bool			operator!=(const stack<A,B> &lhs, const stack<A,B> &rhs);
		template <class A, class B>
		friend bool			operator<(const stack<A,B> &lhs, const stack<A,B> &rhs);
		template <class A, class B>
		friend bool			operator<=(const stack<A,B> &lhs, const stack<A,B> &rhs);
		template <class A, class B>
		friend bool			operator>(const stack<A,B> &lhs, const stack<A,B> &rhs);
		template <class A, class B>
		friend bool			operator>=(const stack<A,B> &lhs, const stack<A,B> &rhs);
};

template <class T, class Container>
bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs._ctnr == rhs._ctnr; }

template <class T, class Container>
bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs._ctnr != rhs._ctnr; }

template <class T, class Container>
bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs._ctnr < rhs._ctnr; }

template <class T, class Container>
bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs._ctnr <= rhs._ctnr; }

template <class T, class Container>
bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs._ctnr > rhs._ctnr; }

template <class T, class Container>
bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs._ctnr >= rhs._ctnr; }

}

#endif