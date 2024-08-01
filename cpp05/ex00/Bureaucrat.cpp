/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:52:08 by schennal          #+#    #+#             */
/*   Updated: 2024/07/25 19:19:31 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150){
    //std::cout << "Bureaucrat" << name <<  " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name){
    //std::cout << "Bureaucrat" << name <<  " constructor called" << std::endl;
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
    //std::cout << "Bureaucrat Null Constructor called" << std::endl;
    if (name == NULL || name->empty()){
        throw NullStringException();
    }
    (void)grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other){
    //std::cout << "Bureaucrat Copy constructor called" << std::endl;
    *this = other;
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat &other){
    //std::cout << "Bureaucrat assignment operator called" << std::endl;
    if(this != &other){
        this->grade = other.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(){
    //std::cout << "Bureaucrat destructor called" << std::endl;
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