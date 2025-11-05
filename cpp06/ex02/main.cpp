/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:30:00 by strodrig          #+#    #+#             */
/*   Updated: 2025/11/05 15:30:00 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// Declaração das funções
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

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

int main(void)
{
	// Inicializa o gerador de números aleatórios
	std::srand(std::time(NULL));

	std::cout << BOLD << CYAN << "\n╔══════════════════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << BOLD << CYAN << "║           DYNAMIC TYPE IDENTIFICATION TEST           ║" << RESET << std::endl;
	std::cout << BOLD << CYAN << "╚══════════════════════════════════════════════════════╝" << RESET << std::endl;

	// Teste 1: Geração aleatória e identificação múltipla
	printTitle("TEST 1: Random Generation (10 instances)");
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << BLUE << "Instance #" << (i + 1) << ":" << RESET << std::endl;
		Base* obj = generate();

		std::cout << "  " << MAGENTA << "→ Identify by pointer: " << RESET;
		identify(obj);

		std::cout << "  " << MAGENTA << "→ Identify by reference: " << RESET;
		identify(*obj);

		delete obj;
		std::cout << std::endl;
	}

	// Teste 2: Criar instâncias específicas e testar
	printTitle("TEST 2: Specific Instance Testing");

	std::cout << BOLD << BLUE << "\n[A] Testing class A:" << RESET << std::endl;
	Base* a = new A();
	std::cout << "  " << MAGENTA << "Pointer identification: " << RESET;
	identify(a);
	std::cout << "  " << MAGENTA << "Reference identification: " << RESET;
	identify(*a);
	delete a;

	std::cout << BOLD << BLUE << "\n[B] Testing class B:" << RESET << std::endl;
	Base* b = new B();
	std::cout << "  " << MAGENTA << "Pointer identification: " << RESET;
	identify(b);
	std::cout << "  " << MAGENTA << "Reference identification: " << RESET;
	identify(*b);
	delete b;

	std::cout << BOLD << BLUE << "\n[C] Testing class C:" << RESET << std::endl;
	Base* c = new C();
	std::cout << "  " << MAGENTA << "Pointer identification: " << RESET;
	identify(c);
	std::cout << "  " << MAGENTA << "Reference identification: " << RESET;
	identify(*c);
	delete c;

	// Teste 3: Array de Base pointers
	printTitle("TEST 3: Array of Base Pointers");
	std::cout << std::endl;

	const int arraySize = 5;
	Base* baseArray[arraySize];

	// Gera instâncias aleatórias
	std::cout << BLUE << "Generating " << arraySize << " random instances..." << RESET << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		baseArray[i] = generate();
	}

	std::cout << std::endl;
	std::cout << BLUE << "Identifying all instances:" << RESET << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "  " << MAGENTA << "[" << i << "] By pointer: " << RESET;
		identify(baseArray[i]);
		std::cout << "      " << MAGENTA << "By reference: " << RESET;
		identify(*baseArray[i]);
	}

	// Limpa memória
	std::cout << std::endl;
	std::cout << YELLOW << "Cleaning up memory..." << RESET << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		delete baseArray[i];
	}

	// Teste 4: Verificação de polimorfismo
	printTitle("TEST 4: Polymorphism Verification");
	std::cout << std::endl;

	std::cout << BLUE << "Creating different types and storing as Base*:" << RESET << std::endl;
	Base* polyA = new A();
	Base* polyB = new B();
	Base* polyC = new C();

	std::cout << "\n" << MAGENTA << "All three are Base* pointers, but identify() can distinguish them:" << RESET << std::endl;
	std::cout << "  polyA type: "; identify(polyA);
	std::cout << "  polyB type: "; identify(polyB);
	std::cout << "  polyC type: "; identify(polyC);

	std::cout << "\n" << MAGENTA << "Using references (no pointers allowed in identify(Base&)):" << RESET << std::endl;
	std::cout << "  polyA type: "; identify(*polyA);
	std::cout << "  polyB type: "; identify(*polyB);
	std::cout << "  polyC type: "; identify(*polyC);

	delete polyA;
	delete polyB;
	delete polyC;

	std::cout << std::endl;
	return (0);
}
