#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testForm(Bureaucrat &b, AForm &f) {
	std::cout << b << std::endl;
	std::cout << f << std::endl;

	b.signForm(f);
	b.executeForm(f);
}

int main() {
	std::cout << "=========================== TESTING SHRUBBERY CREATION FORM (SUCCESS) ==========================" << std::endl;
	try {
		Bureaucrat highRankBureaucrat("Alice", 1);
		ShrubberyCreationForm shrubberyForm("home");
		testForm(highRankBureaucrat, shrubberyForm);
	} catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=========================== TESTING ROBOTOMY REQUEST FORM (SUCCESS) ==========================" << std::endl;
	try {
		Bureaucrat midRankBureaucrat("Bob", 40);
		RobotomyRequestForm robotomyForm("Bender");

		testForm(midRankBureaucrat, robotomyForm);
	} catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=========================== TESTING PRESIDENTIAL PARDON FORM (SUCCESS) ==========================" << std::endl;
	try {
		Bureaucrat highRankBureaucrat("Charlie", 5);
		PresidentialPardonForm pardonForm("Alice");

		testForm(highRankBureaucrat, pardonForm);
	} catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=========================== TESTING (FAIL) EXEC GRADE TOO LOW ==========================" << std::endl;
	{
		Bureaucrat executor("ExecFail", 60);
		AForm *robotomyForm = new RobotomyRequestForm("Claptrap");
		try {
			std::cout << executor << std::endl;
			std::cout << *robotomyForm << std::endl;

			executor.signForm(*robotomyForm);

			std::cout << *robotomyForm << std::endl;

			executor.executeForm(*robotomyForm);

			delete robotomyForm;
		} catch (std::exception &e) {
			std::cerr << "Caught expected exception: " << e.what() << std::endl;
			delete robotomyForm;
		}
	}

	std::cout << std::endl << "=========================== TESTING (FAIL) SIGN GRADE TOO LOW ==========================" << std::endl;
	{
		Bureaucrat lowRank("Lowly", 150);
		AForm *shrubberyForm = new ShrubberyCreationForm("backyard");
		try {
			std::cout << lowRank << std::endl;
			std::cout << *shrubberyForm << std::endl;

			lowRank.signForm(*shrubberyForm);

			lowRank.executeForm(*shrubberyForm);

			delete shrubberyForm;
		} catch (std::exception &e) {
			std::cerr << "Caught expected exception (from execute): " << e.what() << std::endl;
			delete shrubberyForm;
		}
	}

	std::cout << std::endl << "=========================== TESTING (FAIL) EXECUTE NOT SIGNED ==========================" << std::endl;
	{
		Bureaucrat highRank("Powerful", 1);
		AForm *pardonForm = new PresidentialPardonForm("Ford");
		try {
			std::cout << highRank << std::endl;
			std::cout << *pardonForm << std::endl;

			std::cout << "Skipping signing process..." << std::endl;

			highRank.executeForm(*pardonForm);

			delete pardonForm;
		} catch (std::exception &e) {
			std::cerr << "Caught expected exception: " << e.what() << std::endl;
			delete pardonForm;
		}
	}

	return 0;
}
