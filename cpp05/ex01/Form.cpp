/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:13:08 by schennal          #+#    #+#             */
/*   Updated: 2024/07/25 22:07:31 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//contructor
Form::Form(): name("Default"), sign(false), signGrade(150), execGrade(150){
    //std::cout << "Form" << name <<  " constructor called" << std::endl;
}

Form::Form(const std::string &name, int signGrade, int execGrade)
        : name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
{
    //std::cout << "Form" << name <<  " constructor called" << std::endl;
     if (name.empty()){
        throw NullStringException();
    }
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    else if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
}

//copy constructor
Form::Form(const Form & other)
    :name(other.name), sign(other.sign), signGrade(other.signGrade), execGrade(other.execGrade){
    //std::cout << "Form Copy constructor called" << std::endl;
    *this = other;
}

//assignment operator
Form & Form::operator = (const Form &other){
    //std::cout << "Form assignment operator called" << std::endl;
    if(this != &other){
        this->sign = other.sign;
    }
    return (*this);
}

//null exception
Form::Form(const std::string *name, const int signGrade, const int execGrade)
        : name(""), sign(false), signGrade(signGrade), execGrade(execGrade){
  //std::cout << "Form Null Constructor called" << std::endl;
    if (name == NULL || name->empty()){
        throw NullStringException();
    }
    (void)signGrade;
    (void)execGrade;
}

Form::~Form(){
    //std::cout << "Form destructor called" << std::endl;
}

//Getters
const std::string Form::getName() const{
    return(name);
}

bool Form::getSign() const{
    return(sign);
}

int Form::getsignGrade() const{
    return(signGrade);
}

int Form::getexecGrade() const{
    return(execGrade);
}

//Member Functions
void Form::beSigned(Bureaucrat const & bureaucrat){
    if (sign == true){
        std::cerr << CYAN "Form already signed" DEFAULT << std::endl;
    }
    else if (bureaucrat.getGrade() > this->getsignGrade())
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else {
        sign = true;
        // std::cout << "Form signed by " << bureaucrat.getName() << std::endl;
    }
}

//Exceptions
const char * Form::NullStringException::what() const throw(){
    return RED "A Null string was passed" DEFAULT;
}

const char * Form::GradeTooHighException::what() const throw(){
    return RED "Grade is too high" DEFAULT;
}

const char * Form::GradeTooLowException::what() const throw(){
    return RED "Grade is too low" DEFAULT;
}

std::ostream &operator << (std::ostream &o, const Form &form){
    o << "Form Name : " << form.getName() << std::endl;
    o << "\t" << "Signed or Not[1 = signed, 0 = not signed] : " << form.getSign() << std::endl;
    o << "\t" << "Minimum grade required for signing        : " << form.getsignGrade() << std::endl;
    o << "\t" << "Minimum grade required for execution      : " << form.getexecGrade() << std::endl;
    return (o);
}