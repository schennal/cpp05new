/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:56:18 by schennal          #+#    #+#             */
/*   Updated: 2024/07/30 07:55:52 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("Default"){
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    :  AForm("PresidentialPardonForm", 25, 5), target(target){
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
    if (target.empty()){
        throw NullStringException();
    }
}

// PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
//     :  AForm("PresidentialPardonForm", 25, 5), target(target){
//     //std::cout << "PresidentialPardonForm Null Constructor called" << std::endl;
//     if (target.empty()){
//         throw NullStringException();
//     }
// }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    :  AForm(other), target(other.target){
    std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
    *this = other;
}

PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm &other){
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if(this != &other){
        this->target = other.target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat & executor) const{
    if (getSign() == true && executor.getGrade() <= getexecGrade()){
        std::cout << GREEN << target << " has been pardoned by Zaphod Beeblebrox." << DEFAULT << std::endl;
    }
    else if (executor.getGrade() < getexecGrade())
        throw GradeTooLowException();
    else
        throw FormNotSignedException();
}