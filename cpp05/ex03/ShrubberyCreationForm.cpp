/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:18:05 by schennal          #+#    #+#             */
/*   Updated: 2024/07/30 07:58:19 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream> 
// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137), target("Default") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
    if (target.empty()) {
        throw NullStringException();
    }
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

// Assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);  // Copy base class data
        this->target = other.target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// Execute method
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (AForm::getSign() && executor.getGrade() <= AForm::getexecGrade()) {
        std::ofstream file((target + "_shrubbery").c_str());
        if (file.is_open()) {
            file << ASCII_TREE << std::endl;
            file.close();
        } else {
            throw std::ios_base::failure("Failed to open file.");
        }
    } else if (executor.getGrade() < AForm::getexecGrade()) {
        throw AForm::GradeTooLowException();
    } else {
        throw AForm::FormNotSignedException();
    }
}
