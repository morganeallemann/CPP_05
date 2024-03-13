/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
    private :
        std::string _target;
        // Required grades: sign 72, exec 45
    public :
        /* CONSTRUCTOR */
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        /* COPY CONSTRUCTOR */
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        /* DESTRUCTOR */
        virtual ~RobotomyRequestForm();
        /* SURCHARGED OPERATOR */
        RobotomyRequestForm  &operator=(RobotomyRequestForm const &rhs);
        /* GETTER */
        std::string getTarget(void);
        /* MEMBER FUNCTIONS */
        virtual void    execute(Bureaucrat const & executor) const;
        
};
std::ostream &	operator<<(std::ostream & o, RobotomyRequestForm *rhs);

#endif