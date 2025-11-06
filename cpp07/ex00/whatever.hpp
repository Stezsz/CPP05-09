/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:02:31 by strodrig          #+#    #+#             */
/*   Updated: 2025/11/06 14:02:31 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T &a, T &b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T	const &	min(T const &a, T const &b)
{
	return (a < b ? a : b);
}

template<typename T>
T	const &	max(T const &a, T const &b)
{
	return (a > b ? a : b);
}

#endif
