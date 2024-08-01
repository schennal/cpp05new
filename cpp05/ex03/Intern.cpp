/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:17:27 by schennal          #+#    #+#             */
/*   Updated: 2024/07/31 17:17:29 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include <string>

// Constructor
Intern::Intern() {
    // std::cout << "Intern constructor called" << std::endl;
}

// Copy Constructor
Intern::Intern(const Intern &other) {
    // std::cout << "Intern Copy constructor called" << std::endl;
    *this = other;
}

// Assignment Operator
Intern &Intern::operator=(const Intern &other) {
    // std::cout << "Intern assignment operator called" << std::endl;
    (void)other;
    return *this;
}

// Destructor
Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

// Static member functions for form creation
static AForm *makePresidentPardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

static AForm *makeRobotomyRequestForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

static AForm *makeShrubberyCreationForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

// Implementation of makeForm
AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget) {
    // Array of form names
    static const std::string forms[3] = {
        "PresidentialPardonForm",
        "RobotomyRequestForm",
        "ShrubberyCreationForm"
    };

    // Array of form creation functions
    typedef AForm *(*FormCreationFunction)(const std::string &);
    static const FormCreationFunction formCreators[3] = {
        makePresidentPardonForm,
        makeRobotomyRequestForm,
        makeShrubberyCreationForm
    };

    // Find the form and create it
    for (int i = 0; i < 3; i++) {
        if (forms[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](formTarget);
        }
    }

    // If form is not found
    std::cout << "Form " << formName << " not found" << std::endl;
    return nullptr;
}


