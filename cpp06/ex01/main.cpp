/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:44:32 by strodrig          #+#    #+#             */
/*   Updated: 2025/11/05 13:44:32 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <iomanip>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void printSeparator(void)
{
	std::cout << CYAN << "════════════════════════════════════════════════════════" << RESET << std::endl;
}

void printTitle(const std::string& title)
{
	std::cout << std::endl;
	printSeparator();
	std::cout << BOLD << YELLOW << "  " << title << RESET << std::endl;
	printSeparator();
}

void testSerialization(Data& data, const std::string& testName)
{
	printTitle("TEST: " + testName);

	// Mostrar dados originais
	std::cout << BOLD << BLUE << "\n[1] Original Data:" << RESET << std::endl;
	std::cout << "  " << MAGENTA << "Address: " << RESET << &data << std::endl;
	std::cout << "  " << MAGENTA << "Name:    " << RESET << "\"" << data.name << "\"" << std::endl;
	std::cout << "  " << MAGENTA << "Value:   " << RESET << data.value << std::endl;
	std::cout << "  " << MAGENTA << "Price:   " << RESET << std::fixed << std::setprecision(2) << data.price << std::endl;

	// Serialização
	std::cout << BOLD << BLUE << "\n[2] Serialization Process:" << RESET << std::endl;
	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "  " << MAGENTA << "Pointer -> uintptr_t: " << RESET << serialized;
	std::cout << " (0x" << std::hex << serialized << std::dec << ")" << std::endl;

	// Desserialização
	std::cout << BOLD << BLUE << "\n[3] Deserialization Process:" << RESET << std::endl;
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "  " << MAGENTA << "uintptr_t -> Pointer: " << RESET << deserialized << std::endl;

	// Verificação dos dados
	std::cout << BOLD << BLUE << "\n[4] Deserialized Data:" << RESET << std::endl;
	std::cout << "  " << MAGENTA << "Address: " << RESET << deserialized << std::endl;
	std::cout << "  " << MAGENTA << "Name:    " << RESET << "\"" << deserialized->name << "\"" << std::endl;
	std::cout << "  " << MAGENTA << "Value:   " << RESET << deserialized->value << std::endl;
	std::cout << "  " << MAGENTA << "Price:   " << RESET << std::fixed << std::setprecision(2) << deserialized->price << std::endl;

	// Resultado da verificação
	std::cout << BOLD << BLUE << "\n[5] Verification:" << RESET << std::endl;

	if (deserialized == &data)
	{
		std::cout << "  " << GREEN << "✓ Pointer comparison: SUCCESS" << RESET << std::endl;
		std::cout << "    Original and deserialized pointers are EQUAL!" << std::endl;
	}
	else
	{
		std::cout << "  " << RED << "✗ Pointer comparison: FAILURE" << RESET << std::endl;
		std::cout << "    Original and deserialized pointers are DIFFERENT!" << std::endl;
	}

	// Verificação dos valores
	bool dataIntegrity = (deserialized->name == data.name &&
	                      deserialized->value == data.value &&
	                      deserialized->price == data.price);

	if (dataIntegrity)
	{
		std::cout << "  " << GREEN << "✓ Data integrity: SUCCESS" << RESET << std::endl;
		std::cout << "    All data members are intact!" << std::endl;
	}
	else
	{
		std::cout << "  " << RED << "✗ Data integrity: FAILURE" << RESET << std::endl;
		std::cout << "    Data members were corrupted!" << std::endl;
	}
}

int main(void)
{
	std::cout << BOLD << CYAN << "\n╔══════════════════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << BOLD << CYAN << "║         SERIALIZATION / DESERIALIZATION TEST         ║" << RESET << std::endl;
	std::cout << BOLD << CYAN << "╚══════════════════════════════════════════════════════╝" << RESET << std::endl;

	// Teste 1: Produto
	Data product;
	product.name = "Laptop";
	product.value = 1;
	product.price = 999.99;
	testSerialization(product, "Product Item");

	// Teste 2: Cliente
	Data client;
	client.name = "John Doe";
	client.value = 12345;
	client.price = 0.0;
	testSerialization(client, "Client Information");

	// Teste 3: Temperatura
	Data temperature;
	temperature.name = "Weather Data";
	temperature.value = -15;
	temperature.price = 23.5;
	testSerialization(temperature, "Temperature Reading");

	// Teste 4: Valores extremos
	Data extreme;
	extreme.name = "Edge Case";
	extreme.value = 2147483647;
	extreme.price = 123456789.99;
	testSerialization(extreme, "Extreme Values");

	std::cout << std::endl;
	return (0);
}
