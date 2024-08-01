/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:34:36 by schennal          #+#    #+#             */
/*   Updated: 2024/07/30 07:53:10 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//contructor
AForm::AForm(): name("Default"), sign(false), signGrade(150), execGrade(150){
    std::cout << "AForm" << name <<  " constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int signGrade, int execGrade)
        : name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
{
    std::cout << "AForm" << name <<  " constructor called" << std::endl;
     if (name.empty()){
        throw NullStringException();
    }
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    else if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
}

//copy constructor
AForm::AForm(const AForm & other)
    :name(other.name), sign(other.sign), signGrade(other.signGrade), execGrade(other.execGrade){
    std::cout << "AForm Copy constructor called" << std::endl;
    *this = other;
}

//assignment operator
AForm & AForm::operator = (const AForm &other){
    std::cout << "AForm assignment operator called" << std::endl;
    if(this != &other){
        this->sign = other.sign;
    }
    return (*this);
}

AForm::~AForm(){
    std::cout << "AForm destructor called" << std::endl;
}

//Getters
const std::string AForm::getName() const{
    return(name);
}

bool AForm::getSign() const{
    return(sign);
}

int AForm::getsignGrade() const{
    return(signGrade);
}

int AForm::getexecGrade() const{
    return(execGrade);
}

//Member Functions
void AForm::beSigned(Bureaucrat const & bureaucrat){
    if (sign == true){
        std::cerr << CYAN "AForm already signed" DEFAULT << std::endl;
    }
    else if (bureaucrat.getGrade() > this->getsignGrade())
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else {
        sign = true;
    }
}

//Exceptions
const char * AForm::NullStringException::what() const throw(){
    return RED "A Null string was passed" DEFAULT;
}

const char * AForm::GradeTooHighException::what() const throw(){
    return RED "Grade is too high" DEFAULT;
}

const char * AForm::GradeTooLowException::what() const throw(){
    return RED "Grade is too low" DEFAULT;
}

const char * AForm::FormNotSignedException::what() const throw(){
    return RED "Bureaucrat cannot sign this Form" DEFAULT;
}

std::ostream &operator << (std::ostream &o, const AForm &Aform){
    o << "AForm Name : " << Aform.getName() << std::endl;
    o << "\t" << "Signed or Not[1 = signed, 0 = not signed] : " << Aform.getSign() << std::endl;
    o << "\t" << "Minimum grade required for signing        : " << Aform.getsignGrade() << std::endl;
    o << "\t" << "Minimum grade required for execution      : " << Aform.getexecGrade() << std::endl;
    return (o);
}