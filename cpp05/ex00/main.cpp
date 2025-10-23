/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:13:13 by strodrig          #+#    #+#             */
/*   Updated: 2025/10/23 10:13:13 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void) {
	{
		std::cout << "=========================== TESTING RICHARD | GRADE 1 ==========================" << std::endl << std::endl;
		Bureaucrat	a("Richard", 1);

		try {
			a.incrementGrade();
		} catch (Bureaucrat::GradeTooHighException &error) {
			std::cerr << error.what() << std::endl;
		} catch (std::exception &error) {
			std::cerr << error.what() << std::endl;
		} catch (...) {
			std::cerr << "Unknow error" << std::endl;
		}
		std::cout << a << std::endl;
		std::cout << std::endl << "=========================== TESTING RICHARD | GRADE 1 ==========================" << std::endl << std::endl;
	}
	{
		std::cout << "=========================== TESTING HARRY | GRADE 150 ==========================" << std::endl << std::endl;
		Bureaucrat	b("Harry", 150);

		try {
			b.decrementGrade();
		} catch (Bureaucrat::GradeTooLowException &error) {
			std::cerr << error.what() << std::endl;
		} catch (std::exception &error) {
			std::cerr << error.what() << std::endl;
		} catch (...) {
			std::cerr << "Unknow error" << std::endl;
		}
		std::cout << b << std::endl;
		std::cout << std::endl << "=========================== TESTING HARRY | GRADE 150 ==========================" << std::endl << std::endl;
	}
	{
		std::cout << "=========================== TESTING LAURENCE | GRADE 151 ==========================" << std::endl << std::endl;
		try {
			Bureaucrat	b("Laurence", 151);
		} catch (Bureaucrat::GradeTooLowException &error) {
			std::cerr << error.what() << std::endl;
		} catch (std::exception &error) {
			std::cerr << error.what() << std::endl;
		} catch (...) {
			std::cerr << "Unknow error" << std::endl;
		}
		std::cout << std::endl << "=========================== TESTING LAURENCE | GRADE 151 ==========================" << std::endl << std::endl;
	}
	{
		std::cout << "=========================== TESTING DERICK | GRADE 0 ==========================" << std::endl << std::endl;
		try {
			Bureaucrat	b("Derick", 0);
		} catch (Bureaucrat::GradeTooLowException &error) {
			std::cerr << error.what() << std::endl;
		} catch (std::exception &error) {
			std::cerr << error.what() << std::endl;
		} catch (...) {
			std::cerr << "Unknow error" << std::endl;
		}
		std::cout << std::endl << "=========================== TESTING DERICK | GRADE 0 ==========================" << std::endl << std::endl;
	}
	{
		std::cout << "=========================== TESTING ROBERT | GRADE 1 - POSITIVE INFINITY ==========================" << std::endl << std::endl;
		Bureaucrat	b("Robert", 1);
		std::cout << b << std::endl;
		try {
			while (true)
				b.decrementGrade();
		} catch (Bureaucrat::GradeTooLowException &error) {
			std::cerr << error.what() << std::endl;
		} catch (std::exception &error) {
			std::cerr << error.what() << std::endl;
		} catch (...) {
			std::cerr << "Unknow error" << std::endl;
		}
		std::cout << std::endl << "=========================== TESTING ROBERT | GRADE 1 - POSITIVE INFINITY ==========================" << std::endl << std::endl;
	}
	{
		std::cout << "=========================== TESTING JOHN | GRADE 150 - NEGATIVE INFINITY ==========================" << std::endl << std::endl;
		Bureaucrat	b("John", 150);
		std::cout << b << std::endl;
		try {
			while (true)
				b.incrementGrade();
		} catch (Bureaucrat::GradeTooLowException &error) {
			std::cerr << error.what() << std::endl;
		} catch (std::exception &error) {
			std::cerr << error.what() << std::endl;
		} catch (...) {
			std::cerr << "Unknow error" << std::endl;
		}
		std::cout << std::endl << "=========================== TESTING JOHN | GRADE 150 - NEGATIVE INFINITY ==========================" << std::endl << std::endl;
	}
}
