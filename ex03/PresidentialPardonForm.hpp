/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
    private :
        std::string _target;
        // Required grades: sign 25, exec 5
    public :
        /* CONSTRUCTOR */
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        /* COPY CONSTRUCTOR */
        PresidentialPardonForm(PresidentialPardonForm const &copy);
        /* DESTRUCTOR */
        virtual ~PresidentialPardonForm();
        /* SURCHARGED OPERATOR */
        PresidentialPardonForm  &operator=(PresidentialPardonForm const &rhs);
        /* GETTER */
        std::string getTarget(void);
        /* MEMBER FUNCTIONS */
        virtual void    execute(Bureaucrat const & executor) const;
        
};
std::ostream &	operator<<(std::ostream & o, PresidentialPardonForm *rhs);

#endif