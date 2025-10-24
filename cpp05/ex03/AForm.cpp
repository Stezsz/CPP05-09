/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:33:05 by strodrig          #+#    #+#             */
/*   Updated: 2025/10/23 10:33:05 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm Destructor called" << std::endl;
}

AForm::AForm(const std::string name, int signGrade, int executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm Parameterized Constructor called" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade)
{
	std::cout << "AForm Copy Constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm Copy Assignment Operator called" << std::endl;
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

std::string AForm::getName(void) const
{
	return this->_name;
}

bool AForm::getIsSigned(void) const
{
	return this->_isSigned;
}

int AForm::getSignGrade(void) const
{
	return this->_signGrade;
}

int AForm::getExecuteGrade(void) const
{
	return this->_executeGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm Exception: Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm Exception: Grade too low";
}

std::ostream& operator<<(std::ostream &out, const AForm &form)
{
	out << "AForm Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
	return out;
}
