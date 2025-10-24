/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:07:52 by strodrig          #+#    #+#             */
/*   Updated: 2025/10/23 10:07:52 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
	//std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	//std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	//std::cout << "Bureaucrat Parameterized Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	//std::cout << "Bureaucrat Copy Constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat Copy Assignment Operator called" << std::endl;
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high, cannot be greater than 1.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low, cannot be less than 150.");
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}

void	Bureaucrat::signForm(AForm &obj) {
	try {
		obj.beSigned(*this);
		std::cout << _name << " signed " << obj.getName() << std::endl;
	} catch (AForm::GradeTooLowException &error) {
		std::cerr << _name << " couldn't sign " << obj.getName() << " because " << error.what() << std::endl;
	} catch (std::exception &error) {
		std::cerr << error.what() << std::endl;
	} catch (...) {
		std::cerr << "Unknown error" << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &Form) {
	try {
		Form.execute(*this);
		std::cout << _name << " executed " << Form.getName() << std::endl;
	} catch (std::exception &error) {
		std::cerr << _name << " couldn't execute " << Form.getName() << " because " << error.what() << std::endl;
	} catch (...) {
		std::cerr << "Unknown error" << std::endl;
	}
}
