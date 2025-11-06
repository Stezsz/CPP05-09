/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:10:18 by strodrig          #+#    #+#             */
/*   Updated: 2025/11/06 16:10:18 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template<typename T>
class Array
{
	private:
		T*				_array;
		unsigned int	_size;
	public:
		Array() : _array(NULL), _size(0) {}

		Array(unsigned int n) : _array(new T[n]()), _size(n) {}

		Array(Array const & src) : _array(NULL), _size(0)
		{
			*this = src;
		}

		~Array()
		{
			if (_array != NULL)
				delete [] _array;
		}

		Array & operator=(Array const & other)
		{
			if (this != &other)
			{
				if (_array != NULL)
					delete [] _array;

				_size = other._size;
				if (_size > 0)
				{
					_array = new T[_size];
					for (unsigned int i = 0; i < _size; i++)
						_array[i] = other._array[i];
				}
				else
					_array = NULL;
				}
			return *this;
		}
		T & operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::exception();
			return _array[index];
		}

		T const & operator[](unsigned int index) const
		{
			if (index >= _size)
				throw std::exception();
			return _array[index];
		}

		unsigned int size() const
		{
			return _size;
		}
};

#endif
