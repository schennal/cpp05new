/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:33:46 by schennal          #+#    #+#             */
/*   Updated: 2024/07/27 18:33:53 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool sign;
        const int signGrade;
        const int execGrade;
        
    public:
        Form();
        Form(const std::string &name, const int signGrade, const int execGrade);
        Form(const std::string *name, const int signGrade, const int execGrade);
        Form(const Form & other);
        Form &operator = (const Form &other);
        ~Form();

        const std::string getName() const;
        bool getSign() const;
        int getsignGrade() const;
        int getexecGrade() const;

        void beSigned(Bureaucrat const & bureaucrat);

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
        
};

std::ostream &operator << (std::ostream &o, const Form &form);

#endif