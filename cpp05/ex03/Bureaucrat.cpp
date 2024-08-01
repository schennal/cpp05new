/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:33:09 by schennal          #+#    #+#             */
/*   Updated: 2024/07/30 07:51:37 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150){
    std::cout << "Bureaucrat" << name <<  " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name){
    std::cout << "Bureaucrat" << name <<  " constructor called" << std::endl;
    if (name.empty()){
        throw NullStringException();
    }
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        this->grade = grade;
}

Bureaucrat::Bureaucrat(std::string const * name, int grade) {
    std::cout << "Bureaucrat Null Constructor called" << std::endl;
    if (name == NULL || name->empty()){
        throw NullStringException();
    }
    (void)grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other){
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
    *this = other;
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat &other){
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if(this != &other){
        this->grade = other.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string Bureaucrat::getName() const{
    return(name);
}

int Bureaucrat::getGrade() const{
    return(grade);
}

void Bureaucrat::incrementGrade(){
    if (grade > 1)
        grade--;
    else
        throw GradeTooHighException();
    
}

void Bureaucrat::decrementGrade(){
    if (grade < 150)
        grade++;
    else
        throw GradeTooLowException();
}

const char * Bureaucrat::NullStringException::what() const throw(){
    return RED "A Null string was passed" DEFAULT;
}

const char * Bureaucrat::GradeTooHighException::what() const throw(){
    return RED "Grade is too high" DEFAULT;
}

const char * Bureaucrat::GradeTooLowException::what() const throw(){
    return RED "Grade is too low" DEFAULT;
}

std::ostream &operator << (std::ostream &o, const Bureaucrat &bureaucrat){
    o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (o);
}

void Bureaucrat::signForm(AForm & form)
{
    try
    {
    	form.beSigned(*this);
		std::cout << GREEN << name << " signed " << form.getName() << DEFAULT << std::endl;
    }
    catch(const std::exception& e)
    {
		std::cout << RED << name << " couldn't sign " << form.getName() << " because " << e.what() << "." << DEFAULT << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << GREEN << name << " executed " << form.getName() << DEFAULT << std::endl;
    }
    catch(const std::exception& e)
    {
		std::cout << RED << name << " couldn't execute the form " << form.getName() << " because " << e.what() << "." << DEFAULT << std::endl;
    }
}