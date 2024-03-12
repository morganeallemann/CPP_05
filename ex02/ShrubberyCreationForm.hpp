/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SchrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCHRUBBERYCREATIONFORM_HPP
# define SCHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class SchrubberyCreationForm : public AForm {
    private :
        std::string _target;
        // Required grades: sign 145, exec 137
    public :
        /* CONSTRUCTOR */
        SchrubberyCreationForm();
        SchrubberyCreationForm(std::string target);
        /* COPY CONSTRUCTOR */
        SchrubberyCreationForm(SchrubberyCreationForm const &copy);
        /* DESTRUCTOR */
        virtual ~SchrubberyCreationForm();
        /* SURCHARGED OPERATOR */
        SchrubberyCreationForm  &operator=(SchrubberyCreationForm const &rhs);
        /* MEMBER FUNCTIONS */
        virtual void    execute(Bureaucrat const & executor) const;
            

};

#endif
