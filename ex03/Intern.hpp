/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;

class Intern{
    private:

    public:
        /* CONSTRUCTOR */
        Intern();
        /* COPY CONSTRUCTOR */
        Intern(Intern const &copy);
        /* DESTRUCTOR */
        ~Intern();
        /* SURCHARGED OPERATOR */
        Intern &operator=(Intern const &rhs);
        /* MEMBER FUNCTIONS */
        AForm *makeForm(std::string nameForm, std::string target);
};

AForm *doPre(const std::string target);
AForm *doRob(const std::string target);
AForm *doShrub(const std::string target);

#endif
