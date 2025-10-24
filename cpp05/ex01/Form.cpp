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

#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(void) : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
	//std::cout << "Form Default Constructor called" << std::endl;
}

Form::~Form(void)
{
	//std::cout << "Form Destructor called" << std::endl;
}

Form::Form(const std::string name, int signGrade, int executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	//std::cout << "Form Parameterized Constructor called" << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade)
{
	std::cout << "Form Copy Constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form Copy Assignment Operator called" << std::endl;
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

std::string Form::getName(void) const
{
	return this->_name;
}

bool Form::getIsSigned(void) const
{
	return this->_isSigned;
}

int Form::getSignGrade(void) const
{
	return this->_signGrade;
}

int Form::getExecuteGrade(void) const
{
	return this->_executeGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form Exception: Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form Exception: Grade too low";
}

std::ostream& operator<<(std::ostream &out, const Form &form)
{
	out << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
	return out;
}

