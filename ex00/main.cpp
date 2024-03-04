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

int main(){
    std::cout << "------ Test without exceptions ------" << std::endl;
    try{
        Bureaucrat george("George", 20);
    }
    catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
    std::cout << "------------------------------------" << std::endl;
    std::cout << "---- Test with a grade too high ----" << std::endl;
    try{
        Bureaucrat steve("Steve", 0);
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    std::cout << "----- Test with a grade too low ----" << std::endl;
    try{
        Bureaucrat john("John", 151);
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    std::cout << "--------- Test with upgrade --------" << std::endl;
    try{
        Bureaucrat lena("Lena", 4);
        lena.upGrade();
        std::cout << lena << std::endl;
        lena.upGrade();
        std::cout << lena << std::endl;
        lena.upGrade();
        std::cout << lena << std::endl;
        lena.upGrade();
        std::cout << lena << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    std::cout << "------- Test with downgrade --------" << std::endl;
    try{
        Bureaucrat paul("Paul", 148);
        paul.downGrade();
        std::cout << paul << std::endl;
        paul.downGrade();
        std::cout << paul << std::endl;
        paul.downGrade();
        std::cout << paul << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    return (0);
}