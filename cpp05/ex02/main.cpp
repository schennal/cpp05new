/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:28:32 by schennal          #+#    #+#             */
/*   Updated: 2024/07/30 16:34:24 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:58:48 by asajid            #+#    #+#             */
/*   Updated: 2024/05/10 10:05:35 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

// int main()
// {
//     try
//     {
//         std::cout << "******SHRUBBERY CREATION SUCCESS TEST********" << std::endl;
//         Bureaucrat b = Bureaucrat("amina", 137);
//         ShrubberyCreationForm shrub("Shrub");
//         b.signForm(shrub);
//         b.executeForm(shrub);
//         std::cout << b << std::endl;
//         std::cout << shrub << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }
//     try
//     {
//         std::cout << "**SHRUBBERY CREATION INVALID EXEC_GRADE TEST**" << std::endl;
//         Bureaucrat b = Bureaucrat("amina", 138);
//         ShrubberyCreationForm shrub("Shrub");
//         b.signForm(shrub);
//         b.executeForm(shrub);
//         std::cout << b << std::endl;
//         std::cout << shrub << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }
//     try
//     {
//         std::cout << "**SHRUBBERY CREATION INVALID SIGN_GRADE TEST**" << std::endl;
//         Bureaucrat b = Bureaucrat("amina", 146);
//         ShrubberyCreationForm shrub("Shrub");
//         b.signForm(shrub);
//         b.executeForm(shrub);
//         std::cout << b << std::endl;
//         std::cout << shrub << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }
//     try
//     {
//         std::cout << "**ROBOTOMY SIGN FAIL TEST**" << std::endl;
//         Bureaucrat b = Bureaucrat("amina", 146);
//         RobotomyRequestForm robot("Robot");
//         b.signForm(robot);
//         b.executeForm(robot);
//         std::cout << b << std::endl;
//         std::cout << robot << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }
//     try
//     {
//         std::cout << "**ROBOTOMY SIGN SUCCESS TEST**" << std::endl;
//         Bureaucrat b = Bureaucrat("amina", 41);
//         RobotomyRequestForm robot("Robot");
//         b.signForm(robot);
//         b.executeForm(robot);
//         std::cout << b << std::endl;
//         std::cout << robot << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }
//     try
//     {
//         std::cout << "PRESIDENTIAL PARDON SIGN TEST POSITIVE" << std::endl;
//         Bureaucrat b = Bureaucrat("amina", 4);
//         PresidentialPardonForm pardon("Class A");
//         b.signForm(pardon);
//         b.executeForm(pardon);
//         std::cout << b << std::endl;
//         std::cout << pardon << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }
// }

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    // Create bureaucrats with different grades
    Bureaucrat lowGradeBureaucrat("LowGrade", 150);
    Bureaucrat highGradeBureaucrat("HighGrade", 1);
    std::cout << "-------------------------------------------------------" << std::endl;
    // Create forms with different targets
    ShrubberyCreationForm shrubberyForm("Home");
    RobotomyRequestForm robotomyForm("Robot");
    PresidentialPardonForm pardonForm("Alice");
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    // Try to sign forms with bureaucrats having insufficient grade
    std::cout << "\nSigning forms with low-grade bureaucrat:" << std::endl;
    
    try {
        lowGradeBureaucrat.signForm(shrubberyForm);
        lowGradeBureaucrat.signForm(robotomyForm);
        lowGradeBureaucrat.signForm(pardonForm);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    // Try to execute forms with bureaucrats having insufficient grade
    std::cout << "Trying to execute forms with low-grade bureaucrat:" << std::endl;

    try {
        lowGradeBureaucrat.executeForm(shrubberyForm);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        lowGradeBureaucrat.executeForm(robotomyForm);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        lowGradeBureaucrat.executeForm(pardonForm);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    // Sign the forms with a bureaucrat who has sufficient grade to sign
    std::cout << "\nSigning forms with high-grade bureaucrat:" << std::endl;
    
    try {
        highGradeBureaucrat.signForm(shrubberyForm);
        highGradeBureaucrat.signForm(robotomyForm);
        highGradeBureaucrat.signForm(pardonForm);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Try to execute signed forms with a bureaucrat having sufficient grade
    std::cout << "\nTrying to execute signed forms with high-grade bureaucrat:" << std::endl;

    try {
        highGradeBureaucrat.executeForm(shrubberyForm);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        highGradeBureaucrat.executeForm(robotomyForm);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        highGradeBureaucrat.executeForm(pardonForm);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    return 0;
}


// int main()
// {
//     try
//     {
//         std::cout << "******SHRUBBERY CREATION SUCCESS TEST********" << std::endl;
//         Bureaucrat b = Bureaucrat("amina", 137);
//         ShrubberyCreationForm shrub("Shrub");
//         b.signForm(shrub);
//         b.executeForm(shrub);
//         std::cout << b << std::endl;
//         std::cout << shrub << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }
//     try
//     {
//         std::cout << "**SHRUBBERY CREATION INVALID EXEC_GRADE TEST**" << std::endl;
//         Bureaucrat b = Bureaucrat("amina", 138);
//         ShrubberyCreationForm shrub("Shrub");
//         b.signForm(shrub);
//         b.executeForm(shrub);
//         std::cout << b << std::endl;
//         std::cout << shrub << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }
//     try
//     {
//         std::cout << "**SHRUBBERY CREATION INVALID SIGN_GRADE TEST**" << std::endl;
//         Bureaucrat b = Bureaucrat("amina", 146);
//         ShrubberyCreationForm shrub("Shrub");
//         b.signForm(shrub);
//         b.executeForm(shrub);
//         std::cout << b << std::endl;
//         std::cout << shrub << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }
//     try
//     {
//         std::cout << "**ROBOTOMY SIGN FAIL TEST**" << std::endl;
//         Bureaucrat b = Bureaucrat("amina", 146);
//         RobotomyRequestForm robot("Robot");
//         b.signForm(robot);
//         b.executeForm(robot);
//         std::cout << b << std::endl;
//         std::cout << robot << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }
//     try
//     {
//         std::cout << "**ROBOTOMY SIGN SUCCESS TEST**" << std::endl;
//         Bureaucrat b = Bureaucrat("amina", 41);
//         RobotomyRequestForm robot("Robot");
//         b.signForm(robot);
//         b.executeForm(robot);
//         std::cout << b << std::endl;
//         std::cout << robot << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }
//     try
//     {
//         std::cout << "PRESIDENTIAL PARDON SIGN TEST POSITIVE" << std::endl;
//         Bureaucrat b = Bureaucrat("amina", 4);
//         PresidentialPardonForm pardon("Class A");
//         b.signForm(pardon);
//         b.executeForm(pardon);
//         std::cout << b << std::endl;
//         std::cout << pardon << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }
// }

