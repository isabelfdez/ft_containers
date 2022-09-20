/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:55:28 by isfernan          #+#    #+#             */
/*   Updated: 2022/09/20 15:31:43 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

namespace ft {

template <typename T, typename Allocator = std::allocator<T> >

class vector
{
	public:
	// Redefinitions
		typedef	Allocator											allocator_type;
		typedef typename allocator_type::value_type					value_type;			// T
        typedef typename allocator_type::pointer					pointer;			// T*
        typedef typename allocator_type::const_pointer				const_pointer;		// const T*
		typedef typename allocator_type::reference					reference;			// T&
        typedef typename allocator_type::const_reference			const_reference;	// const T&
        typedef typename allocator_type::size_type					size_type;			// std::size_t
		//typedef	T													value_type;
		//typedef size_t												size_type;

	// Constructors & Destructor
		vector(void) { };

	private:
		pointer			_data;
		size_type		_size;
		size_type		_capacity;
		allocator_type	_allocator;

		// This function does not support downsizing
		void	reAlloc(size_type  newCapacity)
		{
			//  1. Allocate a new block of memory
			//pointer	newData = new T[newCapacity];
			pointer	newData = _allocator.allocate(newCapacity);
			
			//	2. Copy (move) existing elements into new blck of memory
			for (size_type i = 0; i < _size; i++)
				newData[i] = _data[i]; //  This is copying, not moving
			//for (size_type i = 0; i < _size; i++)
			//	_allocator.construct(newData[i], _data[i]); //  This is copying, not moving

			//	3. Delete old block of memory
			//delete[] _data;
			_allocator.destroy(_data);
			_allocator.deallocate(_data, _capacity);
			_data = newData;
			_capacity = newCapacity;
		}
	
	public: // Member functions in alphabetical order
		// capacity
		size_type capacity() const { return (_capacity); }

		// push_back
		void	push_back(const value_type& val)
		{
			if (_size <= _capacity) // Hay que tener en cuenta el tamaño del dato que meto
				reAlloc(2 * _capacity);
			_data[_size++] = val;
		}
		
		// size
		size_type size(void) const	{ return (_size); }

		// operator[]
		
};

}

#endif