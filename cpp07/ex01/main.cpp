/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:00:00 by strodrig          #+#    #+#             */
/*   Updated: 2025/11/06 16:00:00 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template<typename T>
void	printElement(T const &element)
{
	std::cout << element << " ";
}

template<typename T>
void	incrementElement(T &element)
{
	element++;
}

template<typename T>
void	doubleElement(T &element)
{
	element *= 2;
}

void	toUpperCase(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

void	printString(std::string const &str)
{
	std::cout << str << std::endl;
}

int main(void)
{
	std::cout << "=== Test 1: Integer array ===" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intSize = 5;

	std::cout << "Original: ";
	::iter(intArray, intSize, printElement<int>);
	std::cout << std::endl;

	::iter(intArray, intSize, incrementElement<int>);
	std::cout << "After increment: ";
	::iter(intArray, intSize, printElement<int>);
	std::cout << std::endl;

	::iter(intArray, intSize, doubleElement<int>);
	std::cout << "After doubling: ";
	::iter(intArray, intSize, printElement<int>);
	std::cout << std::endl << std::endl;

	std::cout << "=== Test 2: Double array ===" << std::endl;
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleSize = 5;

	std::cout << "Original: ";
	::iter(doubleArray, doubleSize, printElement<double>);
	std::cout << std::endl;

	::iter(doubleArray, doubleSize, doubleElement<double>);
	std::cout << "After doubling: ";
	::iter(doubleArray, doubleSize, printElement<double>);
	std::cout << std::endl << std::endl;

	std::cout << "=== Test 3: String array ===" << std::endl;
	std::string strArray[] = {"hello", "world", "cpp", "templates", "rock"};
	size_t strSize = 5;

	std::cout << "Original:" << std::endl;
	::iter(strArray, strSize, printString);

	::iter(strArray, strSize, toUpperCase);
	std::cout << "After uppercase:" << std::endl;
	::iter(strArray, strSize, printString);
	std::cout << std::endl;

	std::cout << "=== Test 4: Char array ===" << std::endl;
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	size_t charSize = 5;

	std::cout << "Original: ";
	::iter(charArray, charSize, printElement<char>);
	std::cout << std::endl;

	::iter(charArray, charSize, incrementElement<char>);
	std::cout << "After increment: ";
	::iter(charArray, charSize, printElement<char>);
	std::cout << std::endl << std::endl;

	std::cout << "=== Test 5: Empty array (edge case) ===" << std::endl;
	int emptyArray[] = {};
	::iter(emptyArray, 0, printElement<int>);
	std::cout << "No elements printed (empty array)" << std::endl;

	return 0;
}
