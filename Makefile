# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 20:23:06 by oipadeol          #+#    #+#              #
#    Updated: 2021/12/15 22:22:34 by oipadeol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

SRC =	push_swap.c 

FLAGS = -Wall -Werror -Wextra

SUB_DIR = libft

BONUS = checker

B_SRC = checker_src/*.c

SUB_DIR_M = big_sort/*.c stack_movers/*.c input_handling/*.c LIS/*.c\
			small_sort/*.c utils/*.c\

all: $(NAME)

$(NAME): $(SRC) $(SUB_DIR_M) $(SUB_DIR)/*.c
	@cd $(SUB_DIR) && $(MAKE) -s
	@gcc -o $(NAME) $(FLAGS) $(SRC) $(SUB_DIR)/$(SUB_DIR).a $(SUB_DIR_M)
	@echo "push_swap compiled!"

bonus: $(BONUS)

$(BONUS): $(B_SRC) $(SRC) $(SUB_DIR_M) $(SUB_DIR)/*.c
	@cd $(SUB_DIR) && $(MAKE) -s
	@gcc -o checker $(FLAGS) $(B_SRC) $(SUB_DIR)/$(SUB_DIR).a\
	 $(SUB_DIR_M)
	@echo "checker program created"

clean:
	@rm -f $(NAME)
	@rm -f $(BONUS)

clean_libft:
	@cd $(SUB_DIR) && $(MAKE) -s clean

fclean:
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@cd $(SUB_DIR) && $(MAKE) -s fclean

re: fclean all