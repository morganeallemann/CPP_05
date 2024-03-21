/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
    std::cout << "A new intern was created " << std::endl;
}

Intern::Intern(Intern const &copy){
    std::cout << "A new intern was created by copie " << std::endl;
    *this = copy;
}

Intern::~Intern(){
    std::cout << "Intern was destroyed" << std::endl;
}

Intern  &Intern::operator=(Intern const &rhs){
    (void) rhs;
    return (*this);
}

AForm   *doPre(const std::string target){
    return (new PresidentialPardonForm);
}

AForm   *doRob(const std::string target){
    return (new RobotomyRequestForm);
}

AForm   *doShrub(const std::string target){
    return (new ShrubberyCreationForm);
}

AForm   *Intern::makeForm(std::string nameForm, std::string target){
    std::string type[] = {"presidential", "robotomy", "shrubbery"};
    AForm *(*form[])(const std::string target) = {&doPre, &doRob, &doShrub};
    for (int i = 0; i < nameForm.length(); i++){
        nameForm[i] = std::tolower(nameForm[i]);
    }
    for (int i = 0; i < 3; i++){
        if (type[i] == nameForm)
            return (form[i](target));
    }
}