/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Unkown"), _signed(false), _gToSigned(150), _gToExecute(150){
    std::cout << "A new Aform " << this->_name << ", grade to signed: " << this->_gToSigned << " grade to execute: " << this->_gToExecute << " was created !" << std::endl;
}

AForm::AForm(std::string name, int gSigned, int gExecute) : _name(name), _signed(false), _gToSigned(gSigned), _gToExecute(gExecute){
    if (this->_gToExecute > 150 || this->_gToSigned > 150)
        throw GradeTooLowException();
    else if (this->_gToExecute < 1 || this->_gToSigned < 1)
        throw GradeTooLowException();
    std::cout << "A new Aform " << this->_name << ", grade to signed: " << this->_gToSigned << " grade to execute: " << this->_gToExecute << " was created !" << std::endl;
}

AForm::AForm(AForm const &copy) : _name(copy.getName()), _signed(copy.getSigned()), _gToSigned(copy.getGToSigned()), _gToExecute(copy.getGToExecute()){
    std::cout << "A new Aform " << this->_name << ", grade to signed: " << this->_gToSigned << " grade to execute: " << this->_gToExecute << " was created by copie !" << std::endl;
}

AForm::~AForm(){
    std::cout << "AForm " << this->_name << " was destroyed !" << std::endl;
}

AForm    &AForm::operator=(AForm const &rhs){
    this->_signed = rhs.getSigned();    
    return (*this);
}

std::string AForm::getName(void) const{
    return (this->_name);
}

bool        AForm::getSigned(void) const{
    return (this->_signed);
}

int         AForm::getGToSigned(void) const{
    return (this->_gToSigned);
}

int         AForm::getGToExecute(void) const{
    return (this->_gToExecute);
}

void        AForm::beSigned(Bureaucrat &b){
    if (b.getGrade() > this->_gToSigned)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_signed = true;
    return ;
}

char const  *AForm::GradeTooHighException::what(void) const throw(){
    return ("Grade is too high");
}

char const  *AForm::GradeTooLowException::what(void) const throw(){
    return ("Grade is too low");
}

char const *AForm::NotSignedFormException::what(void) const throw(){
    return ("The form need to be signed for execute");
}

std::ostream &	operator<<(std::ostream & o, AForm *rhs){
    std::string sign;
    if (!rhs->getSigned())
        sign = "not signed";
    else
        sign = "signed";
	return (o << rhs->getName() << "form, status: " << sign << ", grade needed to signed: " << rhs->getGToSigned() << ", grade needed to execute: " << rhs->getGToExecute());
}

