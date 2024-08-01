# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schennal <schennal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 10:35:41 by schennal          #+#    #+#              #
#    Updated: 2024/07/22 10:36:40 by schennal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ex00

SRCS		=	main.cpp Bureaucrat.cpp
				
OBJS		=	$(SRCS:%.cpp=%.o)

CC			=	c++

FLAGS		=	-std=c++98 -Wall -Wextra -Werror

RM			=	rm -rf

DEFAULT		=	"\033[0m"
RED			=	"\033[0;31m"
GREEN		=	\033[1;32m
CYAN		=	"\033[3;36m"
MAGENTA		=	"\033[0;35m"

%.o : %.cpp
			@printf $(MAGENTA)
			$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(OBJS) -o $@
			@echo "$(GREEN)$(NAME) is ready ✔️✔️"
			

clean:
			@$(RM) $(OBJS)
			@echo $(RED)"Deleted CPP 05 object file"$(DEFAULT)

fclean:		clean
			@$(RM) $(NAME)
			@echo $(RED)"Deleted CPP 05 executable"$(DEFAULT)

re:			fclean all

.PHONY:		all clean fclean re