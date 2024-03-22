/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class   Bureaucrat {
    private:
        std::string const   _name;
        int                 _grade;

    public:
    /* CONSTRUCTORS */
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    /* COPY CONSTRUCTORS */
    Bureaucrat(Bureaucrat const &copy);
    /* DESTRUCTORS */
    ~Bureaucrat();
    /* SURCHARGED OPERATORS */
    Bureaucrat  &operator=(Bureaucrat const &rhs);
    /* GETTERS */
    std::string getName(void) const;
    int         getGrade(void) const;
    /* MEMBER FUNCTIONS */
    void        upGrade(void);
    void        downGrade(void);
     /* EXCEPTIONS */
    class GradeTooHighException : public std::exception{
        public:
            virtual char const	*what(void) const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
            virtual char const	*what(void) const throw();
    };
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat &rhs);

#endif