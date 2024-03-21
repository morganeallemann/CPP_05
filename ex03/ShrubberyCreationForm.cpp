/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Schrubbery", 145, 137), _target("Default"){
    std::cout << "New Schrubbery form was created " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Schrubbery", 145, 137), _target(target){
    std::cout << "New Schrubbery form was created " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm("Schrubbery_copy", 145, 137){
    *this = copy;
    std::cout << "New Schrubbery form was created by copie " << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "Schrubbery form was destroyed " << std::endl;
}

ShrubberyCreationForm  &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs){
    this->_target = rhs._target;
    this->_signed = rhs._signed;
    
    return (*this);
}

std::string ShrubberyCreationForm::getTarget(void){
    return (this->_target);
}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
    if (executor.getGrade() > this->_gToExecute)
        throw Bureaucrat::GradeTooLowException();
    if (!this->_signed)
        throw AForm::NotSignedFormException();
    else{
        std::string fname = this->_target;
        fname.append("_schrubbery");
        std::ofstream file(fname.c_str());
        if (file.is_open()){
            file << "    A\n"
                    "   /  \\\n"
                    "  B   C\n"
                    " / \\ / \\\n"
                    "D  E F  G\n";
            file.close();
            std::cout << "File was created and an Ascii tree was writed with success" << std::endl;
        }
        else
            std::cout << "Error: File cannot be opened" << std::endl;
    }
}

std::ostream &	operator<<(std::ostream & o, ShrubberyCreationForm *rhs){
	std::string sign;
    if (!rhs->getSigned())
        sign = "not signed";
    else
        sign = "signed";
    return (o << rhs->getName() << ", status: " << sign << ", grade needed to signed: " << rhs->getGToSigned() << ", grade needed to execute: " << rhs->getGToExecute());
}