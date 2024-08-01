/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:34:11 by schennal          #+#    #+#             */
/*   Updated: 2024/07/25 20:14:10 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

#define DEFAULT	"\033[0m"
#define YELLOW 	"\e[0;33m"
#define GREEN	"\033[1;32m"
#define CYAN	"\033[0;36m"
#define RED 	"\e[0;31m"

class Form;

class Bureaucrat{
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const std::string *name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator = (const Bureaucrat &other);
        virtual ~Bureaucrat();

        const std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException: public std::exception
        {
            public:
                const char *what() const throw();                
        };
        
        class GradeTooLowException: public std::exception
        {
            public:
                const char *what() const throw();                
        };
        class NullStringException: public std::exception
        {
            public:  
                virtual const char * what() const throw();
        };       

        void signForm(Form & form);
};

std::ostream &operator << (std::ostream &o, const Bureaucrat &bureaucrat);

#endif