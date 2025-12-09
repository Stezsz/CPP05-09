/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:10:09 by strodrig          #+#    #+#             */
/*   Updated: 2025/12/09 12:10:09 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
	_stack = other._stack;
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isNumber(const std::string& token) const {
	if (token.empty())
		return false;

	size_t start = 0;

	if (token[0] == '-' || token[0] == '+')
		start = 1;
	if (start >= token.length())
		return false;
	for (size_t i = start; i < token.length(); i++) {
		if (!isdigit(token[i]))
			return false;
	}
	return true;
}

int RPN::calculate(int a, int b, char op) const {
	switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error");
			return a / b;
		default:
			throw std::runtime_error("Error");
	}
}

int RPN::evaluate(const std::string& expression) {
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (isNumber(token)) {
			int num = 0;
			std::stringstream ss(token);
			ss >> num;

			if (num < 0 || num >= 10) {
				throw std::runtime_error("Error");
			}

			_stack.push(num);
		} else if (isOperator(token)) {
			if (_stack.size() < 2) {
				throw std::runtime_error("Error");
			}

			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();

			int result = calculate(a, b, token[0]);
			_stack.push(result);
		} else {
			throw std::runtime_error("Error");
		}
	}

	if (_stack.size() != 1) {
		throw std::runtime_error("Error");
	}

	return _stack.top();
}


