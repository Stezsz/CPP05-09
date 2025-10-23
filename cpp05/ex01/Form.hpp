/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:33:01 by strodrig          #+#    #+#             */
/*   Updated: 2025/10/23 10:33:01 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;
	public:
		Form(void);
		~Form(void);
		Form(const std::string name, int signGrade, int executeGrade);
		Form(const Form &copy);
		Form &operator=(const Form &other);

		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;

		void beSigned(const Bureaucrat &bureaucrat);
		void beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
}

std::ostream&	operator<<(std::ostream &out, const Form &form);

#endif
