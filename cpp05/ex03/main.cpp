#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	srand(time(NULL));

	Intern someRandomIntern;
	Bureaucrat highRankBureaucrat("Alice", 1);
	AForm* formPtr = NULL;

	std::cout << "=========================== TESTE 1: Robotomy Request (Sucesso) ==========================" << std::endl;

	formPtr = someRandomIntern.makeForm("robotomy request", "Bender");

	if (formPtr)
	{
		highRankBureaucrat.signForm(*formPtr);
		highRankBureaucrat.executeForm(*formPtr);
		delete formPtr;
	}

	std::cout << std::endl << "=========================== TESTE 2: Presidential Pardon (Sucesso) ==========================" << std::endl;

	formPtr = someRandomIntern.makeForm("presidential pardon", "Zaphod");

	if (formPtr)
	{
		highRankBureaucrat.signForm(*formPtr);
		highRankBureaucrat.executeForm(*formPtr);
		delete formPtr;
	}

	std::cout << std::endl << "=========================== TESTE 3: Shrubbery Creation (Sucesso) ==========================" << std::endl;

	formPtr = someRandomIntern.makeForm("shrubbery creation", "home");

	if (formPtr)
	{
		highRankBureaucrat.signForm(*formPtr);
		highRankBureaucrat.executeForm(*formPtr);
		delete formPtr;
	}


	std::cout << std::endl << "=========================== TESTE 4: Formulário Inválido (Falha) ==========================" << std::endl;

	formPtr = someRandomIntern.makeForm("invalid form name", "Gullible");

	if (formPtr == NULL)
	{
		std::cout << "Intern correctly failed to create form." << std::endl;
	}
	else
	{
		std::cout << "TEST FAILED: Intern created a form that should not exist." << std::endl;
		delete formPtr;
	}

	return 0;
}
