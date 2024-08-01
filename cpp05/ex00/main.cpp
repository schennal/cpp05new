/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:37:36 by schennal          #+#    #+#             */
/*   Updated: 2024/07/25 19:57:15 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat higher("Higher", 3);
        std::cout << higher <<std::endl;
        
        Bureaucrat lower("Lower", 150);
        std::cout << lower <<std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "Exception " << e.what() << std::endl;
    }
    std::cout << "-------------------------------------------------------" << std::endl;
    std:: cout << std::endl;
    std:: cout << YELLOW "Increment and Decrement" DEFAULT << std::endl;
    try
    {
        {
        Bureaucrat higher("Higher", 2);
        std::cout << higher <<std::endl;
        Bureaucrat lower("Lower", 70);
        std::cout << lower <<std::endl;
        std:: cout << std::endl;
        higher.incrementGrade();
        std::cout << higher <<std::endl;
        lower.decrementGrade();
        std::cout << lower <<std::endl;
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << "Exception " << e.what() << std::endl;
    }    
}