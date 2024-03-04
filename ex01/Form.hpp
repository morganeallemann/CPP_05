/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class   Form{
    private:
        std::string const   _name;
        bool                _signed;
        int const           _gToSigned;
        int const           _gToExecute;

    public:
        /* CONSTRUCTORS */
        Form();
        Form(std::string name, int gSigned, int gExecute);
        /* COPY CONSTRUCTOR */
        Form(Form const &copy);
        /* DESTRUCTORS */
        ~Form();
        /* SURCHARGED OPERATOR */
        Form    &operator=(Form const &rhs);
        /* GETTERS */
        std::string getName(void) const;
        bool        getSigned(void) const;
        int         getGToSigned(void) const;
        int         getGToExecute(void) const;
        /* MEMBER FUNCTIONS */
        void    beSigned(Bureaucrat &b);
        void    signForm(Bureaucrat &b);
        /* EXCEPTIONS */
        class   GradeTooHighException : public std::exception{
            public:
                virtual char const	*what(void) const throw();
        };
        class   GradeTooLowException : public std::exception{
            public:
                virtual char const *what(void) const throw();
        };
};

std::ostream &	operator<<(std::ostream & o, Form const & rhs);

#endif
