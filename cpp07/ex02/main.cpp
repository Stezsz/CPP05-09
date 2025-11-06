/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:30:00 by strodrig          #+#    #+#             */
/*   Updated: 2025/11/06 16:30:00 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
	// Test 1: Empty array
	std::cout << "=== Test 1: Empty array ===" << std::endl;
	Array<int> emptyArray;
	std::cout << "Empty array size: " << emptyArray.size() << std::endl;
	std::cout << std::endl;

	// Test 2: Array with size
	std::cout << "=== Test 2: Integer array with size 5 ===" << std::endl;
	Array<int> numbers(5);
	std::cout << "Size: " << numbers.size() << std::endl;
	std::cout << "Default initialized values: ";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	// Modify values
	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;
	std::cout << "After modification: ";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl << std::endl;

	// Test 3: Copy constructor
	std::cout << "=== Test 3: Copy constructor ===" << std::endl;
	Array<int> copy(numbers);
	std::cout << "Copy size: " << copy.size() << std::endl;
	std::cout << "Copy values: ";
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << std::endl;

	// Modify original to test deep copy
	numbers[0] = 999;
	std::cout << "After modifying original[0] to 999:" << std::endl;
	std::cout << "Original[0]: " << numbers[0] << std::endl;
	std::cout << "Copy[0]: " << copy[0] << " (should still be 0)" << std::endl;
	std::cout << std::endl;

	// Test 4: Assignment operator
	std::cout << "=== Test 4: Assignment operator ===" << std::endl;
	Array<int> assigned;
	assigned = numbers;
	std::cout << "Assigned size: " << assigned.size() << std::endl;
	std::cout << "Assigned values: ";
	for (unsigned int i = 0; i < assigned.size(); i++)
		std::cout << assigned[i] << " ";
	std::cout << std::endl;

	// Modify to test deep copy
	numbers[1] = 888;
	std::cout << "After modifying original[1] to 888:" << std::endl;
	std::cout << "Original[1]: " << numbers[1] << std::endl;
	std::cout << "Assigned[1]: " << assigned[1] << " (should still be 10)" << std::endl;
	std::cout << std::endl;

	// Test 5: Exception handling
	std::cout << "=== Test 5: Exception handling ===" << std::endl;
	try
	{
		std::cout << "Trying to access index 10 (out of bounds)..." << std::endl;
		std::cout << numbers[10] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Trying to access index -1 (negative)..." << std::endl;
		std::cout << numbers[-1] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Trying to access empty array[0]..." << std::endl;
		std::cout << emptyArray[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 6: String array
	std::cout << "=== Test 6: String array ===" << std::endl;
	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "C++";
	std::cout << "String array: ";
	for (unsigned int i = 0; i < strings.size(); i++)
		std::cout << strings[i] << " ";
	std::cout << std::endl << std::endl;

	// Test 7: Large array (subject test)
	std::cout << "=== Test 7: Large array (MAX_VAL = " << MAX_VAL << ") ===" << std::endl;
	Array<int> largeArray(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		largeArray[i] = value;
		mirror[i] = value;
	}

	// Test scope and destructor
	{
		Array<int> tmp = largeArray;
		Array<int> test(tmp);
	}

	// Verify values remain intact
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != largeArray[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			delete [] mirror;
			return 1;
		}
	}

	// Test out of bounds on large array
	try
	{
		largeArray[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception (negative index): " << e.what() << std::endl;
	}
	try
	{
		largeArray[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception (index = MAX_VAL): " << e.what() << std::endl;
	}

	// Fill with values
	for (int i = 0; i < MAX_VAL; i++)
	{
		largeArray[i] = rand();
	}
	delete [] mirror;

	std::cout << "Large array test completed successfully!" << std::endl;
	std::cout << std::endl;

	// Test 8: Const array
	std::cout << "=== Test 8: Const array ===" << std::endl;
	const Array<int> constArray(3);
	std::cout << "Const array size: " << constArray.size() << std::endl;
	std::cout << "Const array[0]: " << constArray[0] << std::endl;
	std::cout << std::endl;

	std::cout << "=== All tests passed! ===" << std::endl;

	return 0;
}
