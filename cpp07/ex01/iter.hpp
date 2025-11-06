/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:58:54 by strodrig          #+#    #+#             */
/*   Updated: 2025/11/06 15:58:54 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template<typename T, typename F>
void	iter(T *array, size_t size, F function)
{
	for (size_t i = 0; i < size; i++)
		function(array[i]);
}

#endif
