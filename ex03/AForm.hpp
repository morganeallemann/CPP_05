/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAFORM_HPP
# define AAFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class   AForm{
    protected:
        std::string const   _name;
        bool                _signed;
        int const           _gToSigned;
        int const           _gToExecute;

    public:
        /* CONSTRUCTORS */
        AForm();
        AForm(std::string name, int gSigned, int gExecute);
        /* COPY CONSTRUCTOR */
        AForm(AForm const &copy);
        /* DESTRUCTORS */
        virtual ~AForm();
        /* SURCHARGED OPERATOR */
        AForm    &operator=(AForm const &rhs);
        /* GETTERS */
        std::string getName(void) const;
        bool        getSigned(void) const;
        int         getGToSigned(void) const;
        int         getGToExecute(void) const;
        /* MEMBER FUNCTIONS */
        void    beSigned(Bureaucrat &b);
        virtual void    execute(Bureaucrat const & executor) const = 0;
        /* EXCEPTIONS */
        class   GradeTooHighException : public std::exception{
            public:
                virtual char const	*what(void) const throw();
        };
        class   GradeTooLowException : public std::exception{
            public:
                virtual char const *what(void) const throw();
        };
        class   NotSignedFormException : public std::exception{
            public :
                virtual char const *what(void) const throw();
        };
};

std::ostream &	operator<<(std::ostream & o, AForm *rhs);

#endif
