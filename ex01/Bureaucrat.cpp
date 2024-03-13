/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unkown"), _grade(150){
    std::cout << "A new Bureaucrat " << this->_name << ", grade: " << this->_grade << " was created !" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "A new Bureaucrat " << this->_name << ", grade: " << this->_grade << " was created !" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy.getName()), _grade(copy.getGrade()){
    std::cout << "A new Bureaucrat " << this->_name << ", grade: " << this->_grade << " was created by copie !" << std::endl;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat " << this->_name << " was destroyed !" << std::endl;
}

Bureaucrat  &Bureaucrat::operator=(Bureaucrat const &rhs){
    this->_grade = rhs.getGrade();
    return (*this);
}

std::string Bureaucrat::getName(void) const{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const{
    return (this->_grade);
}

void    Bureaucrat::upGrade(void){
    this->_grade--;
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void    Bureaucrat::downGrade(void){
    this->_grade++;
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void    Bureaucrat::signForm(Form &form){
    if (form.getSigned())
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    else
        std::cout << this->_name << " couldn't sign " << form.getName() << " because is grade is too low or the form is already sign" << std::endl;
    return ;
}

char const	*Bureaucrat::GradeTooHighException::what(void) const throw(){
    return ("Grade too high");
}

char const	*Bureaucrat::GradeTooLowException::what(void) const throw(){
    return ("Grade too low");
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat *rhs){
	return (o << rhs->getName() << ", bureaucrat grade : " << rhs->getGrade());
}