/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:59:43 by strodrig          #+#    #+#             */
/*   Updated: 2025/11/05 14:59:43 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>

Base* generate(void)
{
	int	randNum = std::rand() % 3;

	switch (randNum)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& aRef = dynamic_cast<A&>(p);
		(void)aRef;
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception&) {}

	try
	{
		B& bRef = dynamic_cast<B&>(p);
		(void)bRef;
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception&) {}

	try
	{
		C& cRef = dynamic_cast<C&>(p);
		(void)cRef;
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception&) {}

	std::cout << "Unknown type" << std::endl;
}
