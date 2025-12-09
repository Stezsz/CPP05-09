/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:47:12 by strodrig          #+#    #+#             */
/*   Updated: 2025/12/09 12:47:12 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe sorter;

	if (!sorter.parseInput(argc, argv)) {
		return 1;
	}

	sorter.sort();

	return 0;
}
