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

int main(){
    std::cout << "------ Test without exceptions ------" << std::endl;
    try{
        Bureaucrat george("George", 20);
        Form       form("form", 20, 20);
        form.beSigned(george);
        form.signForm(george);
    }
    catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
    std::cout << "------------------------------------" << std::endl;
    std::cout << "---- Test with form's grade too low ----" << std::endl;
    try{
        Form test("test", 160, 20);
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    std::cout << "----- Test with form's grade too high ----" << std::endl;
    try{
        Form test2("test2", 100, 0);
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    std::cout << "--------- Test with signed ---------" << std::endl;
    try{
        Bureaucrat lena("Lena", 4);
        Bureaucrat jack ("Jack", 20);
        Form       test3("test3", 5, 4);
        Form       test4("test4", 5, 1);
        lena.upGrade();
        jack.downGrade();
        std::cout << lena << std::endl;
        std::cout << jack << std::endl;
        std::cout << test3 << std::endl;
        std::cout << test4 << std::endl;
        test3.beSigned(lena);
        test3.signForm(lena);
        test4.beSigned(jack);
        test4.signForm(jack);
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    return (0);
}