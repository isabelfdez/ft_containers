/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:55:28 by isfernan          #+#    #+#             */
/*   Updated: 2022/10/27 18:10:14 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "iterators/iterator_traits.hpp"
# include "iterators/RAIterator.hpp"
# include "iterators/reverse_iterator.hpp"
# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"
# include "algorithms/equal.hpp"
# include "algorithms/lexicographical_compare.hpp"


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
		typedef RAIterator<pointer>										iterator;
		typedef RAIterator<const_pointer>								const_iterator;
		typedef reverse_iterator<iterator>								reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
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
	// copy(4): Constructs a container with a copy of each of the elements in x, in the same order.
		vector(const vector& x)
		{
			_allocator = x._allocator;
			_capacity = x.capacity();
			_size = x.size();
			if (x._capacity > 0)
				_data = _allocator.allocate(_capacity);
			for (size_type i = 0; i <_size; i++)
				_allocator.construct(&_data[i], x._data[i]);
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
		void			assign(InputIterator first, InputIterator last, 
								typename ft::enable_if<!ft::is_integral<InputIterator>::value,
								InputIterator>::type * = NULL)
		{
			this->clear();
			while (first < last)
			{
				this->push_back(*first);
				first++;
			}
		}
		void			assign(size_type n, const value_type& val)
		{
			this->clear();
			if (_size + n > _capacity)
				reAlloc(_size + n);
			for (size_type i = 0; i < n; i++)
				push_back(val);
		}

		// at
		reference		at(size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("vector");
			return (_data[n]);
		}
		const_reference at(size_type n) const
		{
			if (n >= _size)
				throw std::out_of_range("vector");
			return (_data[n]);
		}

		// back
		reference		back() { return _data[_size - 1]; }
		const_reference	back() const { return _data[_size - 1]; }		
		
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

		// empty
		bool			empty() const { return(_size == 0); };

		// end
		iterator		end() { return (iterator(&_data[_size])); }
		const_iterator	end() const { return (const_iterator(&_data[_size])); }

		// erase
		iterator		erase(iterator position)
		{
			size_type	n = position - this->begin();
		
    		for (size_type i = n; i < _size - 1; i++)
    		    _data[i] = _data[i + 1];
			std::cout << _data[n] << std::endl;

			_allocator.destroy(&_data[_size]);
			_size--;
			return (iterator(&_data[n]));
		}
		iterator		erase(iterator first, iterator last)
		{
			size_type	n = first - this->begin();
			size_type	l = last - first;
		
    		iterator it = first;
			while (it != last)
			{
				_allocator.destroy(&_data[n]);
				_allocator.construct(&_data[n], _data[n + l]);
				n++;
				it++;
			}
			while (it != end())
			{
				_allocator.destroy(&_data[n]);
				n++;
				it++;
			}
			_size -= l;
			return first;
		}
		
		// front
		reference		front() { return _data[0]; }
		const_reference	front() const { return _data[0]; }

		// get_allocator
		allocator_type	get_allocator() { return _allocator; }

		// insert
		iterator		insert(iterator position, const value_type& val)
		{
			size_type	dist = 0;

			if (_size > 0)
				dist = position - this->begin();
			if (_size + 1 > _capacity)
				reAlloc(_capacity * 2);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
			for (size_type i = _size; i > dist; i--)
				_allocator.construct(&_data[i], _data[i - 1]);
			_allocator.construct(&_data[dist], val);
			_size++;
			return position;
		}
		void			insert(iterator position, size_type n, const value_type& val)
		{
			size_type 	dist = 0;
			size_type 	dist2 = 0;

			if (_size > 0)
			{
				dist = position - this->begin() + n - 1;
				dist2 = position - this->begin();
			}
			if (_size + n > _capacity)
				reAlloc((_size + n >_capacity * 2) ? _size + n : _capacity * 2);
			for (size_type i = _size + n - 1; i > dist; i--)
				_allocator.construct(&_data[i], _data[i - n]);
			for (size_type i = dist2; i <= dist; i++)
				_allocator.construct(&_data[i], val);
			_size += n;
		}
		template <class InputIterator>
		void			insert(iterator position, InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			size_type dist = 0;
			if (_size > 0)
				dist = position - begin();
			size_type n = last - first;
			if (_size + n > _capacity)
			{
				if (n > _size)
					reserve(_size + n);
				else
					reAlloc(_capacity * 2);
			}
			_size += n;
			for (size_type i = _size - 1; i > dist; i--)
				_allocator.construct(&_data[i], _data[i - n]);
			for (size_type i = 0; i < n; i++)
				_allocator.construct(&_data[dist + i], *(first + i));
		}


		// max_size
		size_type		max_size() const { return _allocator.max_size(); }

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

		// reserve
		void			reserve(size_type n)
		{
			if (n > _capacity)
				reAlloc(n);
		}

		//resize
		void			resize(size_type n, value_type val = value_type())
		{
			if (n < _size)
				for (size_type i = n; i < _size; i++)
					_allocator.destroy(&_data[i]);
			else if (n < _capacity)
				for (size_type i = _size; i < n; i++)
					_allocator.construct(&_data[i], val);
			if (n > _capacity)
			{
				reAlloc((n < 2 * _capacity ? 2 * _capacity : n));
				for (size_type i = _size; i < n; i++)
					_allocator.construct(&_data[i], val);
			}
			_size = n;
		}
		
		// size
		size_type		size(void) const	{ return (_size); }

		// operator[]
		reference		operator[] (size_type n) { return (_data[n]); }
		const_reference	operator[] (size_type n) const { return (_data[n]); }

		// operator=
		vector&			operator= (const vector& x)
		{
			_allocator = x._allocator;
			this->reserve(x._capacity);
			_size = x.size();
			for (size_type i = 0; i < _size; i++)
    		    _allocator.construct(_data + i, *(x._data + i));
			return (*this);
		}
};

// Relational operators

template <typename T, typename Alloc>
bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (0);
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <typename T, typename Alloc>
bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	return (!(lhs == rhs));
}
	
template <typename T, typename Alloc>
bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}
	
template <typename T, typename Alloc>
bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	return (!(lhs > rhs));
}
	
template <typename T, typename Alloc>
bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
}

template <typename T, typename Alloc>
bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	return (!(lhs < rhs));
}


}

#endif