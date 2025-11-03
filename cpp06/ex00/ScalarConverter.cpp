/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:36:28 by strodrig          #+#    #+#             */
/*   Updated: 2025/11/03 18:36:28 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}

static bool isCharLiteral(const std::string &literal) {
	return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

static bool isIntLiteral(const std::string &literal) {
	size_t i = 0;
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	if (i >= literal.length())
		return false;
	for (; i < literal.length(); i++) {
		if (!isdigit(literal[i]))
			return false;
	}
	return true;
}

static bool isFloatLiteral(const std::string &literal) {
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;

	size_t i = 0;
	bool hasDecimalPoint = false;

	if (literal[i] == '-' || literal[i] == '+')
		i++;
	if (i >= literal.length())
		return false;

	for (; i < literal.length() - 1; i++) {
		if (literal[i] == '.') {
			if (hasDecimalPoint)
				return false;
			hasDecimalPoint = true;
		} else if (!isdigit(literal[i])) {
			return false;
		}
	}

	return (literal[literal.length() - 1] == 'f' && hasDecimalPoint);
}

static bool isDoubleLiteral(const std::string &literal) {
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;

	size_t i = 0;
	bool hasDecimalPoint = false;

	if (literal[i] == '-' || literal[i] == '+')
		i++;
	if (i >= literal.length())
		return false;

	for (; i < literal.length(); i++) {
		if (literal[i] == '.') {
			if (hasDecimalPoint)
				return false;
			hasDecimalPoint = true;
		} else if (!isdigit(literal[i])) {
			return false;
		}
	}

	return hasDecimalPoint;
}

static void printChar(double value, bool impossible)
{
	std::cout << "char: ";
	if (impossible || std::isnan(value) || std::isinf(value))
		std::cout << "impossible";
	else if (value < 0 || value > 127)
		std::cout << "impossible";
	else if (value < 32 || value == 127)
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(value) << "'";
	std::cout << std::endl;
}

static void printInt(double value, bool impossible)
{
	std::cout << "int: ";
	if (impossible || std::isnan(value) || std::isinf(value))
		std::cout << "impossible";
	else if (value < INT_MIN || value > INT_MAX)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
}

static void printFloat(double value)
{
	std::cout << "float: ";
	float f = static_cast<float>(value);
	if (std::isnan(value))
		std::cout << "nanf";
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inff" : "-inff");
	else
	{
		std::cout << std::fixed << std::setprecision(1) << f << "f";
	}
	std::cout << std::endl;
}

static void printDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan";
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf");
	else
	{
		std::cout << std::fixed << std::setprecision(1) << value;
	}
	std::cout << std::endl;
}


static void convertFromChar(const std::string &literal) {
	char c = literal[1];
	double value = static_cast<double>(c);

	printChar(value, false);
	printInt(value, false);
	printFloat(value);
	printDouble(value);
}

static void convertFromInt(const std::string &literal) {
	char *end;
	long l = std::strtol(literal.c_str(), &end, 10);
	bool impossible = false;

	if (*end != '\0' || l < INT_MIN || l > INT_MAX)
		impossible = true;

	double value = static_cast<double>(l);

	printChar(value, impossible);
	printInt(value, impossible);
	printFloat(value);
	printDouble(value);
}

static void convertFromFloat(const std::string& literal) {
	char* end;
	float f = std::strtof(literal.c_str(), &end);
	double value = static_cast<double>(f);

	printChar(value, false);
	printInt(value, false);
	printFloat(value);
	printDouble(value);
}

static void convertFromDouble(const std::string& literal) {
	char* end;
	double value = std::strtod(literal.c_str(), &end);

	printChar(value, false);
	printInt(value, false);
	printFloat(value);
	printDouble(value);
}

void ScalarConverter::convert(const std::string &literal) {
	if (literal.empty())
	{
		std::cout << "Error: Empty literal" << std::endl;
		return ;
	}

	if (isCharLiteral(literal))
		convertFromChar(literal);
	else if (isIntLiteral(literal))
		convertFromInt(literal);
	else if (isFloatLiteral(literal))
		convertFromFloat(literal);
	else if (isDoubleLiteral(literal))
		convertFromDouble(literal);
	else
	{
		std::cout << "Error: Invalid literal format" << std::endl;
		return ;
	}
}
