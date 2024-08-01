/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:58:08 by schennal          #+#    #+#             */
/*   Updated: 2024/07/25 22:06:45 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// int main()
// {
// 	try
// 	{
// 			Bureaucrat bureaucrat("John", 50);
// 			Form form("Application Form", 60, 70);
// 			std::cout << bureaucrat << std::endl;
// 			std::cout << form << std::endl;
// 			bureaucrat.signForm(form);
// 			std::cout << form << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}
// 	return 0;
// }


int main()
{
    try
    {
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << YELLOW << "GRADE TOO LOW TO SIGN TEST" << DEFAULT << std::endl;
        Form form("Contract Form", 4, 6);
        Bureaucrat bureaucrat("Alex", 10);
        bureaucrat.signForm(form);
        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try
    {
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << YELLOW << "GRADE OK SIGN TEST" << DEFAULT << std::endl;
        Form form("Rental Agreement", 4, 6);
        Bureaucrat bureaucrat("Boby", 3);
        bureaucrat.signForm(form);
        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try
    {
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << YELLOW << "BE-SIGNED GRADE TOO LOW TEST" << DEFAULT << std::endl;
        Bureaucrat bureaucrat("Claire", 10);
        Form form("Agreement Form", 25, 12);
        form.beSigned(bureaucrat);
        form.beSigned(bureaucrat);
        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
}



