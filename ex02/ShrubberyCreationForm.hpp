/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
    private :
        std::string _target;
        // Required grades: sign 145, exec 137
    public :
        /* CONSTRUCTOR */
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        /* COPY CONSTRUCTOR */
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        /* DESTRUCTOR */
        virtual ~ShrubberyCreationForm();
        /* SURCHARGED OPERATOR */
        ShrubberyCreationForm  &operator=(ShrubberyCreationForm const &rhs);
        /* GETTER */
        std::string getTarget(void);
        /* MEMBER FUNCTIONS */
        virtual void    execute(Bureaucrat const & executor) const;
        
};
std::ostream &	operator<<(std::ostream & o, ShrubberyCreationForm *rhs);

#endif
