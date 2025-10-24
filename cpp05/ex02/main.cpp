/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* main.cpp                                           :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/10/24 16:38:42 by strodrig          #+#    #+#             */
/* Updated: 2025/10/24 17:15:00 by gemini           ###   ########.fr       */
/* */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp" // É uma boa prática incluir a base
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Função helper para evitar repetição
void testForm(Bureaucrat &b, AForm &f) {
	std::cout << b << std::endl;
	std::cout << f << std::endl;

	b.signForm(f); // O Burocrata assina o formulário
	b.executeForm(f); // O Burocrata executa o formulário
}

int main() {
    std::cout << "=========================== TESTING SHRUBBERY CREATION FORM (SUCCESS) ==========================" << std::endl;
    try {
        Bureaucrat highRankBureaucrat("Alice", 1);
        ShrubberyCreationForm shrubberyForm("home"); // Criar na stack para variar
        testForm(highRankBureaucrat, shrubberyForm);
    } catch (std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=========================== TESTING ROBOTOMY REQUEST FORM (SUCCESS) ==========================" << std::endl;
    try {
        Bureaucrat midRankBureaucrat("Bob", 40); // Grade 40
        RobotomyRequestForm robotomyForm("Bender"); // Sign 72, Exec 45

		// Assinatura (OK: 40 <= 72)
		// Execução (OK: 40 <= 45)
        testForm(midRankBureaucrat, robotomyForm);
    } catch (std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=========================== TESTING PRESIDENTIAL PARDON FORM (SUCCESS) ==========================" << std::endl;
    try {
        Bureaucrat highRankBureaucrat("Charlie", 5); // Grade 5
        PresidentialPardonForm pardonForm("Alice"); // Sign 25, Exec 5

		// Assinatura (OK: 5 <= 25)
		// Execução (OK: 5 <= 5)
        testForm(highRankBureaucrat, pardonForm);
    } catch (std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

	std::cout << std::endl << "=========================== TESTING (FAIL) EXEC GRADE TOO LOW ==========================" << std::endl;
	{
		// Teste onde a assinatura funciona, mas a execução falha
		Bureaucrat executor("ExecFail", 60); // Grade 60
        AForm *robotomyForm = new RobotomyRequestForm("Claptrap"); // Sign 72, Exec 45
		try {
			std::cout << executor << std::endl;
			std::cout << *robotomyForm << std::endl;

			// Assinatura (Deve funcionar: 60 <= 72)
			executor.signForm(*robotomyForm);

			std::cout << *robotomyForm << std::endl;

			// Execução (Deve falhar: 60 > 45)
			executor.executeForm(*robotomyForm); // Deve lançar GradeTooLowException

			delete robotomyForm;
		} catch (std::exception &e) {
			std::cerr << "Caught expected exception: " << e.what() << std::endl;
			delete robotomyForm;
		}
	}

	std::cout << std::endl << "=========================== TESTING (FAIL) SIGN GRADE TOO LOW ==========================" << std::endl;
	{
		// Teste onde a assinatura falha
		Bureaucrat lowRank("Lowly", 150); // Grade 150
        AForm *shrubberyForm = new ShrubberyCreationForm("backyard"); // Sign 145, Exec 137
		try {
			std::cout << lowRank << std::endl;
			std::cout << *shrubberyForm << std::endl;

			// Assinatura (Deve falhar: 150 > 145)
			lowRank.signForm(*shrubberyForm);

			// Execução (Deve falhar por não estar assinado)
			lowRank.executeForm(*shrubberyForm);

			delete shrubberyForm;
		} catch (std::exception &e) {
			// A primeira exceção (de signForm) será impressa pela própria função,
			// a segunda (de executeForm) será capturada aqui.
			std::cerr << "Caught expected exception (from execute): " << e.what() << std::endl;
			delete shrubberyForm;
		}
	}

	std::cout << std::endl << "=========================== TESTING (FAIL) EXECUTE NOT SIGNED ==========================" << std::endl;
	{
		// Teste onde a execução falha por não estar assinado
		Bureaucrat highRank("Powerful", 1); // Grade 1
        AForm *pardonForm = new PresidentialPardonForm("Ford"); // Sign 25, Exec 5
		try {
			std::cout << highRank << std::endl;
			std::cout << *pardonForm << std::endl;

			// Não chamamos signForm()
			std::cout << "Skipping signing process..." << std::endl;

			// Execução (Deve falhar por não estar assinado)
			highRank.executeForm(*pardonForm); // Deve lançar exceção

			delete pardonForm;
		} catch (std::exception &e) {
			std::cerr << "Caught expected exception: " << e.what() << std::endl;
			delete pardonForm;
		}
	}

    return 0;
}
