/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:38:42 by strodrig          #+#    #+#             */
/*   Updated: 2025/10/24 16:38:42 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

int main() {
    std::cout << "=========================== TESTING SHRUBBERY CREATION FORM ==========================" << std::endl;

    try {
        Bureaucrat highRankBureaucrat("Alice", 1);
        AForm *shrubberyForm = new ShrubberyCreationForm("home");

        std::cout << highRankBureaucrat << std::endl;
        std::cout << *shrubberyForm << std::endl;

        shrubberyForm->beSigned(highRankBureaucrat);
        std::cout << "After signing: " << std::endl;
        std::cout << *shrubberyForm << std::endl;

        highRankBureaucrat.executeForm(*shrubberyForm);
        delete shrubberyForm;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "=========================== TESTING ROBOTOMY REQUEST FORM ==========================" << std::endl;

    try {
        Bureaucrat midRankBureaucrat("Bob", 50);
        AForm *robotomyForm = new RobotomyRequestForm("Bender");

        std::cout << midRankBureaucrat << std::endl;
        std::cout << *robotomyForm << std::endl;

        robotomyForm->beSigned(midRankBureaucrat);
        std::cout << "After signing: " << std::endl;
        std::cout << *robotomyForm << std::endl;

        midRankBureaucrat.executeForm(*robotomyForm);
        delete robotomyForm;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "=========================== TESTING PRESIDENTIAL PARDON FORM ==========================" << std::endl;

    try {
        Bureaucrat highRankBureaucrat("Charlie", 1);
        AForm *pardonForm = new PresidentialPardonForm("Alice");

        std::cout << highRankBureaucrat << std::endl;
        std::cout << *pardonForm << std::endl;

        pardonForm->beSigned(highRankBureaucrat);
        std::cout << "After signing: " << std::endl;
        std::cout << *pardonForm << std::endl;

        highRankBureaucrat.executeForm(*pardonForm);
        delete pardonForm;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	std::cout << std::endl << "=========================== TESTING PRESIDENTIAL PARDON FORM EXCEPTION ==========================" << std::endl;
	{
		Bureaucrat highRankBureaucrat("Charlie", 32);
		AForm *pardonForm = new PresidentialPardonForm("Alice");
		try {
			std::cout << highRankBureaucrat << std::endl;
			std::cout << *pardonForm << std::endl;

			pardonForm->beSigned(highRankBureaucrat);
			std::cout << "After signing: " << std::endl;
			std::cout << *pardonForm << std::endl;

			highRankBureaucrat.executeForm(*pardonForm);
			delete pardonForm;
		} catch (std::exception &e) {
			delete pardonForm;
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "=========================== TESTING ROBOTOMY REQUEST FORM EXCEPTION ==========================" << std::endl;
	{
		Bureaucrat midRankBureaucrat("Bob", 100);
		AForm *robotomyForm = new RobotomyRequestForm("Bender");
		try {
			std::cout << midRankBureaucrat << std::endl;
			std::cout << *robotomyForm << std::endl;

			robotomyForm->beSigned(midRankBureaucrat);
			std::cout << "After signing: " << std::endl;
			std::cout << *robotomyForm << std::endl;

			midRankBureaucrat.executeForm(*robotomyForm);
			delete robotomyForm;
		} catch (std::exception &e) {
			delete robotomyForm;
			std::cerr << e.what() << std::endl;
		}

	}

	std::cout << std::endl << "=========================== TESTING SHRUBBERY CREATION FORM EXCEPTION ==========================" << std::endl;
	{
		Bureaucrat highRankBureaucrat("Alice", 148);
		AForm *shrubberyForm = new ShrubberyCreationForm("home");
		try {
			std::cout << highRankBureaucrat << std::endl;
			std::cout << *shrubberyForm << std::endl;

			shrubberyForm->beSigned(highRankBureaucrat);
			std::cout << "After signing: " << std::endl;

			highRankBureaucrat.executeForm(*shrubberyForm);
			delete shrubberyForm;
		} catch (std::exception &e) {
			delete shrubberyForm;
			std::cerr << e.what() << std::endl;
		}
	}

    return 0;
}
