/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:35:09 by schennal          #+#    #+#             */
/*   Updated: 2024/08/01 16:08:22 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// int main(void)
// {
//         Intern someRandomIntern;
//         AForm *rrf;
//         rrf = someRandomIntern.makeForm("Presidential Pardon", "Claire");
//         Bureaucrat b = Bureaucrat("benjamin", 1);
//         b.signForm(*rrf);
//         b.executeForm(*rrf);
//         delete rrf;
// }

// // #include "Intern.hpp"
// // #include "Bureaucrat.hpp"
// // #include "PresidentialPardonForm.hpp"
// // #include "RobotomyRequestForm.hpp"
// // #include "ShrubberyCreationForm.hpp"

int main(void)
{
    Intern someRandomIntern;
    AForm *rrf;

    // Correct the form name to match the expected format in makeForm
    rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Claire");

    if (rrf) {
        Bureaucrat b("Benjamin", 1);
        b.signForm(*rrf);
        b.executeForm(*rrf);
        delete rrf;  // Clean up the dynamically allocated form
    } else {
        std::cout << "Failed to create form." << std::endl;
    }

    return 0;
}
