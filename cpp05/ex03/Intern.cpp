/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:34:33 by strodrig          #+#    #+#             */
/*   Updated: 2025/10/24 17:34:33 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

static AForm	*createShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm	*createRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm	*createPresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

static formPair	*makePairs(void)
{
	formPair pairs;
	static formPair formPairs[3];
	pairs = std::make_pair("shrubbery creation", &createShrubberyCreationForm);
	formPairs[0] = pairs;
	pairs = std::make_pair("robotomy request", &createRobotomyRequestForm);
	formPairs[1] = pairs;
	pairs = std::make_pair("presidential pardon", &createPresidentialPardonForm);
	formPairs[2] = pairs;
	return formPairs;
}

Aform *Intern::makeForm(const std::string &formName, const std::string &target)
{
	formPair	*formPairs = makePairs();

	for (int i = 0; i < 3; i++)
	{
		if (formName == formPairs[i].first)
		{
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return (formPairs[i].second)(target);
		}
	}
	std::cout << "Intern could not find the form: " << formName << std::endl;
	return NULL;
}
