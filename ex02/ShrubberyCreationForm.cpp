/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SchrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SchrubberyCreationForm.hpp"

SchrubberyCreationForm() : AForm("Schrubbery", 145, 137), _target("Default"){
    std::cout << "New Schrubbery form was created " << std::endl;
}

SchrubberyCreationForm(std::string target) : AForm(), _target(target){
    std::cout << "New Schrubbery form was created " << std::endl;
}

SchrubberyCreationForm(SchrubberyCreationForm const &copy) : AForm(){
    *this = copy;
    std::cout << "New Schrubbery form was created by copie " << std::endl;
}

~SchrubberyCreationForm(){
    std::cout << "Schrubbery form was destroyed " << std::endl;
}

SchrubberyCreationForm  &SchrubberyCreationForm::operator=(SchrubberyCreationForm const &rhs){
    this->_target = rhs._target;
    this->_gToSigned = rhs._gToSigned;
    this->_gToExecute = rhs._gToExecute;
    this->_name = rhs._name;
    this->_signed = rhs._signed;
    
    return (*this);
}

void    SchrubberyCreationForm::execute(Bureaucrat const &executor) const{

}