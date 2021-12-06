# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 20:23:06 by oipadeol          #+#    #+#              #
#    Updated: 2021/12/05 18:50:52 by oipadeol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c operations.c input_handling.c OK.c wheel_algo.c

#FLAGS = -Wall -Werror -Wextra

FLAGS = 

SUB_DIR = libft

all: $(NAME)

$(NAME): $(SRC) $(SUB_DIR)/*.c
	@cd $(SUB_DIR) && $(MAKE) -s
	@gcc -o $(NAME) $(FLAGS) $(SRC) $(SUB_DIR)/$(SUB_DIR).a
	@$(MAKE) -s clean
	@echo "compiled!"
	@echo ".o files deleted"

bonus: $(NAME)

clean:
	@rm -f *.o
	@cd $(SUB_DIR) && $(MAKE) -s clean

fclean: clean
	@rm -f $(NAME)
	@cd $(SUB_DIR) && $(MAKE) -s fclean

re: fclean all