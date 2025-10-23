/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:36:07 by strodrig          #+#    #+#             */
/*   Updated: 2025/10/23 11:36:07 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=========================== TESTE SUCESSO ==========================" << std::endl;
    try {
        Bureaucrat highRankBureaucrat("Alice", 1);
        Form highSecurityForm("Top Secret", 5, 2);

        std::cout << highRankBureaucrat << std::endl;
        std::cout << highSecurityForm << std::endl;

        highRankBureaucrat.signForm(highSecurityForm);

        std::cout << "Após assinatura: " << std::endl;
        std::cout << highSecurityForm << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Erro inesperado no main: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=========================== TESTE FALHA (RANK BAIXO) ==========================" << std::endl;

    Bureaucrat lowRankBureaucrat("Bob", 150);
    Form classifiedForm("Classified", 50, 25);

    std::cout << lowRankBureaucrat << std::endl;
    std::cout << classifiedForm << std::endl;

    lowRankBureaucrat.signForm(classifiedForm);

    std::cout << "Após tentativa de assinatura: " << std::endl;
    std::cout << classifiedForm << std::endl;


    std::cout << std::endl << "=========================== TESTE LIMITE (SUCESSO) ==========================" << std::endl;
    try {
        Bureaucrat borderlineBureaucrat("Charlie", 50);
        Form borderlineForm("Borderline Document", 50, 25);
        std::cout << borderlineBureaucrat << std::endl;
        std::cout << borderlineForm << std::endl;

        borderlineBureaucrat.signForm(borderlineForm);

        std::cout << "Após assinatura: " << std::endl;
        std::cout << borderlineForm << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Erro inesperado no main: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=========================== TESTE LIMITE (FALHA POR 1) ==========================" << std::endl;

    Bureaucrat nearlyThereBureaucrat("Eve", 51);
    Form toughForm("Tough Form", 50, 25);
    std::cout << nearlyThereBureaucrat << std::endl;
    std::cout << toughForm << std::endl;

    nearlyThereBureaucrat.signForm(toughForm);
    std::cout << "Após tentativa de assinatura: " << std::endl;
    std::cout << toughForm << std::endl;


    std::cout << std::endl << "=========================== TESTE CRIAÇÃO INVÁLIDA ==========================" << std::endl;
    try {
        Form invalidForm("Impossible Form", 0, 150);
    } catch (std::exception &e) {
        std::cerr << "Erro na criação do Form: " << e.what() << std::endl;
    }
    try {
        Form invalidForm2("Impossible Form 2", 1, 200);
    } catch (std::exception &e) {
        std::cerr << "Erro na criação do Form: " << e.what() << std::endl;
    }

    return (0);
}
