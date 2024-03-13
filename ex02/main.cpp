/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>

int main(void)
{
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		AForm *b = new PresidentialPardonForm("default");
		// Form *c = new RobotomyRequestForm();
		// AForm *d = new ShrubberyCreationForm();
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		try
		{
			b->beSigned(*a);
			// b->execute(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << b << std::endl;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		AForm *c = new PresidentialPardonForm("some dude");
		// AForm *d = new AForm(*c);
		// AForm *d = new AForm("Rent Contract", 140, 100); // you are not able to construct an abstract class here
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << std::endl;

		// Try to execute before signing
		try
		{
			c->execute(*b);
		}
		catch (AForm::NotSignedFormException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to execute the AForm " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;
		// Assistant signs the AForm
		try
		{
			c->beSigned(*a);
			// a->signAForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to sign the AForm " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

		// CEO signs the AForm
		std::cout << std::endl;
		std::cout << c;
		std::cout << std::endl;
		try
		{
			c->beSigned(*b);
			// b->signAForm(*c);
		}
		// catch(AForm::GradeTooLowException &e)
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << b->getName() << " was not able to sign the AForm " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;
		std::cout << c;
		std::cout << std::endl;

		// try signing the from again
		std::cout << std::endl;
		b->signAForm(*c);
		std::cout << std::endl;

		// execute the AForm from assistant
		try
		{
			c->execute(*a);
			// a.executeForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to execute the AForm " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;

		// execute AForm from CEO
		try
		{
			c->execute(*b);
			// b.executeForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << b->getName() << " was not able to execute the AForm " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		PresidentialPardonForm *b = new PresidentialPardonForm("this other dude");
		PresidentialPardonForm *c = new PresidentialPardonForm(*b);
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		b->beSigned(*a);
		a->signAForm(*c);
        try{
            b->execute(*a);
		    a->executeForm(*c);
        }
        catch(AForm::NotSignedFormException &e)
		{
			std::cerr << "\033[33m" << b->getName() << " was not able to execute the AForm " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		// c->execute(*a);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Eperor", 1);
		RobotomyRequestForm *b = new RobotomyRequestForm("Bender");
		ShrubberyCreationForm *c = new ShrubberyCreationForm("christmas");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		b->beSigned(*a);
		a->signAForm(*c);
		for (int i= 0; i < 10; i++)
			b->execute(*a);
		// a->executeForm(*c);
        try{
		    c->execute(*a);
        }
        catch(AForm::NotSignedFormException &e)
		{
			std::cerr << "\033[33m" << b->getName() << " was not able to execute the AForm " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
        std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	return (0);
}