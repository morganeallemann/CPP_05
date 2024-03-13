/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Unkown"), _signed(false), _gToSigned(150), _gToExecute(150){
    std::cout << "A new form " << this->_name << ", grade to signed: " << this->_gToSigned << " grade to execute: " << this->_gToExecute << " was created !" << std::endl;
}

Form::Form(std::string name, int gSigned, int gExecute) : _name(name), _signed(false), _gToSigned(gSigned), _gToExecute(gExecute){
    if (this->_gToExecute > 150 || this->_gToSigned > 150)
        throw GradeTooLowException();
    else if (this->_gToExecute < 1 || this->_gToSigned < 1)
        throw GradeTooLowException();
    std::cout << "A new form " << this->_name << ", grade to signed: " << this->_gToSigned << " grade to execute: " << this->_gToExecute << " was created !" << std::endl;
}

Form::Form(Form const &copy) : _name(copy.getName()), _signed(copy.getSigned()), _gToSigned(copy.getGToSigned()), _gToExecute(copy.getGToExecute()){
    std::cout << "A new form " << this->_name << ", grade to signed: " << this->_gToSigned << " grade to execute: " << this->_gToExecute << " was created by copie !" << std::endl;
}

Form::~Form(){
    std::cout << "Form " << this->_name << " was destroyed !" << std::endl;
}

Form    &Form::operator=(Form const &rhs){
    this->_signed = rhs.getSigned();    
    return (*this);
}

std::string Form::getName(void) const{
    return (this->_name);
}

bool        Form::getSigned(void) const{
    return (this->_signed);
}

int         Form::getGToSigned(void) const{
    return (this->_gToSigned);
}

int         Form::getGToExecute(void) const{
    return (this->_gToExecute);
}

void        Form::beSigned(Bureaucrat &b){
    if (b.getGrade() > this->_gToSigned)
        throw Form::GradeTooLowException();
    else
        this->_signed = true;
    return ;
}

void        Form::signForm(Bureaucrat &b){
    if (this->_signed)
        std::cout << b.getName() << " signed " << this->_name << std::endl;
    else
        std::cout << b.getName() << " couldn't sign " << this->_name << " because is grade is too low" << std::endl;
    return ;
}

char const  *Form::GradeTooHighException::what(void) const throw(){
    return ("Grade is too high");
}

char const  *Form::GradeTooLowException::what(void) const throw(){
    return ("Grade is too low");
}

std::ostream &	operator<<(std::ostream & o, Form *rhs){
    std::string sign;
    if (!rhs->getSigned())
        sign = "not signed";
    else
        sign = "signed";
	return (o << rhs->getName() << "form, status: " << sign << ", grade needed to signed: " << rhs->getGToSigned() << ", grade needed to execute: " << rhs->getGToExecute());
}

