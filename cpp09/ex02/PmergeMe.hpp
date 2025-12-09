/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:43:24 by strodrig          #+#    #+#             */
/*   Updated: 2025/12/09 12:43:24 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <sys/time.h>

class PmergeMe {
	private:
		std::vector<int> _vectorData;
		std::deque<int> _dequeData;

		void mergeInsertSortVector(std::vector<int>& arr);
		void insertionSortVector(std::vector<int>& arr, int left, int right);
		void mergeVector(std::vector<int>& arr, int left, int mid, int right);

		void mergeInsertSortDeque(std::deque<int>& arr);
		void insertionSortDeque(std::deque<int>& arr, int left, int right);
		void mergeDeque(std::deque<int>& arr, int left, int mid, int right);

		bool isValidNumber(const std::string& str) const;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		bool parseInput(int argc, char** argv);
		void sort();
		void displayResults(double vectorTime, double dequeTime) const;
};

#endif
