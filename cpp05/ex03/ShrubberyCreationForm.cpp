/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:13:18 by strodrig          #+#    #+#             */
/*   Updated: 2025/10/24 16:13:18 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137)
{
	// std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	// std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->_target = other._target;
		AForm::operator=(other);
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();

	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();

	std::string filename = this->_target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	if (!outfile.is_open())
		throw ShrubberyCreationForm::FileOpenException();
	outfile << "       _-_" << std::endl;
	outfile << "    /~~   ~~\\" << std::endl;
	outfile << " /~~         ~~\\" << std::endl;
	outfile << "{               }" << std::endl;
	outfile << " \\  _-     -_  /" << std::endl;
	outfile << "   ~  \\\\ //  ~" << std::endl;
	outfile << "_- -   | | _- _" << std::endl;
	outfile << "  _ -  | |   -_" << std::endl;
	outfile << "      // \\\\" << std::endl;
	outfile << std::endl;
	outfile.close();
}

const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return "ShrubberyCreationForm Exception: Could not open file";
}
