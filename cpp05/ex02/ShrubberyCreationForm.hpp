/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:18:08 by schennal          #+#    #+#             */
/*   Updated: 2024/07/30 16:30:45 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCRAETIONFORM_HPP
#define SHRUBBERYCRAETIONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

#ifdef ENABLE_ANSI_COLOR
#define ANSI_GREEN "\033[1;32m"
#define ANSI_RESET "\033[0m"
#else
#define ANSI_GREEN ""
#define ANSI_RESET ""
#endif

#define ASCII_TREE ANSI_GREEN \
"                   _____                \n" \
"               _/`__  `\\_             \n" \
"            _/`   `\"`\\_  `\\_          \n" \
"          _/`          `\\_  `\\_        \n" \
"       _/`                `\\_  `\\_     \n" \
"     _/`      _..-''```-.._   `\\_  `\\_  \n" \
"   _/`    _.-'           `-._   `\\_  `\\_ \n" \
" _/`   _.-'                  `-._  `\\_  `\\\n" \
"  _.-'                            `-.  `\\_  `\\ \n" \
" /                                    `-.  `\\_ \n" \
" |                                       `-.  \n" \
" |      _                               _.-'  \n" \
" \\   _/` `\\_                     _.-'      \n" \
"  `-'       `-._             _.-'           \n" \
"             /` `\\       /`                \n" \
"            |     |     |                   \n" \
"            |     |     |                   \n" \
"            |_____|_____|                   \n" \
ANSI_RESET


class Form;

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const std::string *target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator = (const ShrubberyCreationForm &other);
        virtual ~ShrubberyCreationForm();

        void execute(const Bureaucrat & executor) const;
};

#endif