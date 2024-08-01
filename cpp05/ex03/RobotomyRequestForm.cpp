/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:54:14 by schennal          #+#    #+#             */
/*   Updated: 2024/07/30 07:55:19 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("Default"){
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    :  AForm("RobotomyRequestForm", 72, 45), target(target){
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
    if (target.empty()){
        throw NullStringException();
    }
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    :  AForm(other), target(other.target){
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
    target = other.target;
}

RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm &other){
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if(this != &other){
        target = other.target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}


void RobotomyRequestForm::execute(const Bureaucrat & executor) const{
    if (getSign() == true && executor.getGrade() <= getexecGrade()){
        std::cout << CYAN << "DRILLING NOISES......DRRRR......TRRRR" << DEFAULT << std::endl;
        if (rand() % 2)
            std::cout << CYAN << target <<  " has been robotomized successfully" << DEFAULT << std::endl;
        else
            std::cout << CYAN << "Robotomy has failed" << DEFAULT << std::endl;
    }
    else if (executor.getGrade() < getexecGrade())
        throw GradeTooLowException();
    else
        throw FormNotSignedException();
}