/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:33:24 by strodrig          #+#    #+#             */
/*   Updated: 2025/10/23 10:33:24 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

int main() {
    std::cout << "=========================== TESTING FORM CLASS ==========================" << std::endl;

    try {
        Bureaucrat highRankBureaucrat("Alice", 1);
        Form highSecurityForm("Top Secret", 5, 2);

        std::cout << highRankBureaucrat << std::endl;
        std::cout << highSecurityForm << std::endl;

        highSecurityForm.beSigned(highRankBureaucrat);
        std::cout << "After signing: " << std::endl;
        std::cout << highSecurityForm << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "=========================== TESTING FORM CLASS WITH LOW RANK ==========================" << std::endl;

    try {
        Bureaucrat lowRankBureaucrat("Bob", 150);
        Form classifiedForm("Classified", 50, 25);

        std::cout << lowRankBureaucrat << std::endl;
        std::cout << classifiedForm << std::endl;

        classifiedForm.beSigned(lowRankBureaucrat);
        std::cout << "After attempting to sign: " << std::endl;
        std::cout << classifiedForm << std::endl;
    } catch (Form::GradeTooLowException &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "General exception caught: " << e.what() << std::endl;
    }

	std::cout << std::endl << "=========================== BORDERLINE RANK SIGNING TEST ==========================" << std::endl;
	try {
		Bureaucrat borderlineBureaucrat("Charlie", 50);
		Form borderlineForm("Borderline Document", 50, 25);
		std::cout << borderlineBureaucrat << std::endl;
		std::cout << borderlineForm << std::endl;
		borderlineForm.beSigned(borderlineBureaucrat);
		std::cout << "After signing: " << std::endl;
		std::cout << borderlineForm << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "=========================== INSUFFICIENT RANK BY ONE TEST ==========================" << std::endl;
	try {
		Bureaucrat nearlyThereBureaucrat("Eve", 51);
		Form toughForm("Tough Form", 50, 25);
		toughForm.beSigned(nearlyThereBureaucrat);
	} catch (Form::GradeTooLowException &e) {
		std::cerr << "Failed to sign due to: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=========================== INVALID RANK FORM CREATION TEST ==========================" << std::endl;
	try {
		Form invalidForm("Impossible Form", 0, 200);
	} catch (Form::GradeTooHighException &e) {
		std::cerr << "Grade exception: " << e.what() << std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cerr << "Grade exception: " << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	} catch (...) {
		std::cerr << "Unknow error" << std::endl;
	}

    return (0);
}
