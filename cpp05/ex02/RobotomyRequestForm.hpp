/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:11:24 by strodrig          #+#    #+#             */
/*   Updated: 2025/10/24 16:11:24 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		std::string	_target;
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	public:
		RobotomyRequestForm(const std::string &target);
		~RobotomyRequestForm(void);

		void execute(Bureaucrat const & executor) const;

		class RobotomyFailedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
