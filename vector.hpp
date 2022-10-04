/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:55:28 by isfernan          #+#    #+#             */
/*   Updated: 2022/10/04 14:52:22 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "iterators/iterator_traits.hpp"
# include "iterators/RAIterator.hpp"
# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"


namespace ft {

template <typename T, typename Allocator = std::allocator<T> >
class vector
{
	public:
	// Redefinition of member types
		typedef	Allocator												allocator_type;
		typedef T														value_type;			// T
        typedef typename allocator_type::pointer						pointer;			// T*
        typedef typename allocator_type::const_pointer					const_pointer;		// const T*
		typedef typename allocator_type::reference						reference;			// T&
        typedef typename allocator_type::const_reference				const_reference;	// const T&
        typedef typename allocator_type::size_type						size_type;			// std::size_t
		//typedef	T													value_type;
		//typedef size_t												size_type;
		typedef RAIterator<pointer>										iterator;
		typedef RAIterator<const_pointer>								const_iterator;
//		typedef VectorReverseIterator<iterator>							reverse_iterator;
//		typedef VectorReverseIterator<const_iterator>					const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;

	// Constructors & Destructor
	// default (1): Constructs an empty container, with no elements.
		explicit vector(const allocator_type& alloc = allocator_type()) : 
			_data(NULL), _size(0), _capacity(0), _allocator(alloc) { }
	// fill(2): Constructs a container with n elements. Each element is a copy of val.
		explicit vector(size_type n, const value_type& val = value_type(), 
						const allocator_type& alloc = allocator_type()) : 
			_data(NULL), _size(0), _capacity(0), _allocator(alloc)
		{
			reAlloc(n);
			for (size_type i = 0; i < n; i++)
				push_back(val);
		}
	// range(3): Constructs a container with as many elements as the range [first,last),
	//			 with each element constructed from its corresponding element in that range,
	//			 in the same order.
		template <typename InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL) :
			_data(NULL), _size(0), _capacity(0), _allocator(alloc)
		{
			if (last > first)
			{
				reAlloc(last - first);
				while (first < last)
				{
					this->push_back(*first);
					first++;
				}
			}
		}
	// copy: Constructs a container with a copy of each of the elements in x, in the same order.
		vector(const vector& x)
		{
			_allocator = std::allocator::allocator(vector.allocator_type);
			_capacity = x.capacity();
			if (x._capacity > 0)
				_c = _alloc.allocate(_capacity);
			for (size_type i = 0; i <_size; i++)
				_alloc.construct(&_c[i], x._c[i]);
		}

	

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
			pointer	newData = _allocator.allocate(newCapacity, 0);
			
			//	2. Copy (move) existing elements into new block of memory
    		for (size_type i = 0; i < _size; i++)
    		    _allocator.construct(newData + i, *(_data + i));

			//	3. Delete old block of memory
    		for (size_type i = 0; i < _size; i++)
    		    _allocator.destroy(_data + i);
    		_allocator.deallocate(_data, _capacity);

    		// set new stuff, after everything worked out nicely
			/* for (size_type i = 0; i < _size; i++)
				newData[i] = _data[i]; */ // Esto funciona pero no es lo que hace el vector
			//for (size_type i = 0; i < _size; i++)
			//	_allocator.construct(newData[i], _data[i]); //  This is copying, not moving

			//	4. Set new stuff, after everything worked out nicely
			_data = newData;
			_capacity = newCapacity;
		}
	
	public: // Member functions in alphabetical order
		// assign
		template <typename InputIterator>
		void			assign(InputIterator first, InputIterator last/*, 
								typename ft::enable_if<!ft::is_integral<InputIterator>::value,
								InputIterator>::type * = NULL*/)
		{
			this->clear();
			while (first < last)
			{
				this->push_back(*first);
				first++;
			}
		}
		
		// begin
		iterator		begin() { return (iterator(_data)); }
		const_iterator	begin() const { return (const_iterator(_data)); }

		// capacity
		size_type		capacity() const { return (_capacity); }

		// clear
		void			clear()
		{
			for (size_type i = 0; i < _size; i++)
    		    _allocator.destroy(_data + i);
			_size = 0;
		}

		// end
		iterator		end() { return (iterator(&_data[_size])); }
		const_iterator	end() const { return (const_iterator(&_data[_size])); }

		// pop_back
		void			pop_back()
		{
			_allocator.destroy(_data + _size - 1);
			_size--;
			// Aqui habrá que hacer algo con el puntero a end
		}

		// push_back
		void			push_back(const value_type& val)
		{
			if (_size == _capacity) // Hay que tener en cuenta el tamaño del dato que meto
				reAlloc((_capacity > 0) ? 2 * _capacity : 1);
			_allocator.construct(_data + _size, val);
			_size++;
			//_data[_size++] = val;
		}
		
		// size
		size_type		size(void) const	{ return (_size); }

		// operator[]
		reference		operator[] (size_type n) { return (_data[n]); }
		const_reference	operator[] (size_type n) const { return (_data[n]); }
};

}

#endif