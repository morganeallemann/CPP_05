/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: /01/17 15:37:09 by malleman          #+#    #+#                 */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), _target("Default"){
    std::cout << "New Presidential form was created " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5), _target(target){
    std::cout << "New Presidential form was created " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm("Presidential_copy", 25, 5){
    *this = copy;
    std::cout << "New Presidential form was created by copie " << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Presidential form was destroyed " << std::endl;
}

PresidentialPardonForm  &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs){
    this->_target = rhs._target;
    this->_signed = rhs._signed;
    
    return (*this);
}

std::string PresidentialPardonForm::getTarget(void){
    return (this->_target);
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const{
    if (executor.getGrade() > this->_gToExecute)
        throw Bureaucrat::GradeTooLowException();
    if (!this->_signed)
        throw AForm::NotSignedFormException();
    else{
        std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
}

std::ostream &	operator<<(std::ostream & o, PresidentialPardonForm *rhs){
    std::string sign;
    if (!rhs->getSigned())
        sign = "not signed";
    else
        sign = "signed";
	return (o << rhs->getName() << ", status: " << sign << ", grade needed to signed: " << rhs->getGToSigned() << ", grade needed to execute: " << rhs->getGToExecute());
}