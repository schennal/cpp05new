/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:34:39 by schennal          #+#    #+#             */
/*   Updated: 2024/07/27 21:04:18 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        const std::string name;
        bool sign;
        const int signGrade;
        const int execGrade;
        
    public:
        AForm();
        AForm(const std::string &name, const int signGrade, const int execGrade);
        AForm(const AForm & other);
        AForm &operator = (const AForm &other);
        virtual ~AForm();

        const std::string getName() const;
        bool getSign() const;
        int getsignGrade() const;
        int getexecGrade() const;

        void beSigned(Bureaucrat const & bureaucrat);
       
        virtual void execute(const Bureaucrat & executor) const = 0;

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
        class FormNotSignedException: public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
        
};

std::ostream &operator << (std::ostream &o, const AForm &form);

#endif