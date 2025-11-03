/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:36:31 by strodrig          #+#    #+#             */
/*   Updated: 2025/11/03 18:36:31 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
