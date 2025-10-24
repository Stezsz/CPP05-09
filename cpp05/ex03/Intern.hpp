/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:34:30 by strodrig          #+#    #+#             */
/*   Updated: 2025/10/24 17:34:30 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

typedef AForm *(*formCreator)(const std::string &target);
typedef std::pair<std::string, formCreator> formPair;

class Intern
{
	public:
		Intern(void);
		~Intern(void);
		Intern(const Intern &copy);
		Intern &operator=(const Intern &other);

		AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif
