# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/05 00:19:26 by cfarjane          #+#    #+#              #
#    Updated: 2018/02/05 00:39:23 by cfarjane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= gnl
SRC 	= get_next_line.c main.c
FLAGS 	= -ggdb
INCLUDES = -I. -Ilibft/ -Ilibft.a -Llibft/ -lft
CC 		= gcc

OBJ := $(SRC:.c=.o)
CL=\x1b[35m
GREEN=\033[1;32m
RED=\033[1;31m
CL2=\x1b[36m
NC=\033[0m

%.o: %.c
	@$(CC) -c $< -o $@ $(FLAGS)

all:  $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@echo "$(GREEN)[✓]$(NC)$(CL) Objects of libft compiled$(NC)"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(INCLUDES)
	@echo "$(GREEN)[✓]$(NC)$(CL) executable $(NAME) built$(NC)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED)[-]$(NC)$(CL2) Objects of $(NAME) cleaned$(NC)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)[-]$(NC)$(CL2) Library $(NAME) cleaned$(NC)"

re: fclean all
