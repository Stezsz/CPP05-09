/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:32:21 by strodrig          #+#    #+#             */
/*   Updated: 2025/12/05 19:32:21 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		bool loadDatabase(const std::string& filename);
		void processInputFile(const std::string& filename);
		double getExchangeRate(const std::string& date) const;

	private:
		std::map<std::string, double> _database;

		bool isValidDate(const std::string& date) const;
		bool isValidValue(const std::string& value) const;
		double stringToDouble(const std::string& str) const;
		std::string trim(const std::string& str) const;
};

#endif
