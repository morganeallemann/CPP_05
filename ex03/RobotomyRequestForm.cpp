/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: /01/17 15:37:09 by malleman          #+#    #+#                 */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("Default"){
    std::cout << "New Robotomy form was created " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), _target(target){
    std::cout << "New Robotomy form was created " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm("Robotomy_copy", 72, 45){
    *this = copy;
    std::cout << "New Robotomy form was created by copie " << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "Robotomy form was destroyed " << std::endl;
}

RobotomyRequestForm  &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs){
    this->_target = rhs._target;
    this->_signed = rhs._signed;
    
    return (*this);
}

std::string RobotomyRequestForm::getTarget(void){
    return (this->_target);
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const{
    static int failed = 0;
    if (executor.getGrade() > this->_gToExecute)
        throw Bureaucrat::GradeTooLowException();
    if (!this->_signed)
        throw AForm::NotSignedFormException();
    else{
        std::cout << "BrrRRrrrRRrrRrrRRrr" << std::endl;
        if ((failed % 2) == 0)
            std::cout << this->_target << " has been robotomized successfully" << std::endl;
        else
            std::cout << "The robotomy failed !" << std::endl; 
        failed++;
    }
}

std::ostream &	operator<<(std::ostream & o, RobotomyRequestForm *rhs){
	std::string sign;
    if (!rhs->getSigned())
        sign = "not signed";
    else
        sign = "signed";
    return (o << rhs->getName() << ", status: " << sign << ", grade needed to signed: " << rhs->getGToSigned() << ", grade needed to execute: " << rhs->getGToExecute());
}