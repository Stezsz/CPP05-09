/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:30:36 by strodrig          #+#    #+#             */
/*   Updated: 2025/12/05 19:30:36 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange bitcoinExchange;

	if (!bitcoinExchange.loadDatabase("data.csv")) {
		return 1;
	}

	bitcoinExchange.processInputFile(argv[1]);

	return 0;
}
