# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 20:23:06 by oipadeol          #+#    #+#              #
#    Updated: 2021/12/10 16:22:02 by oipadeol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

SRC =	push_swap.c 

#FLAGS = -Wall -Werror -Wextra

FLAGS = 

SUB_DIR = libft

SUB_DIR_M = big_sort/*.c stack_movers/*.c input_handling/*.c LIS/*.c\
			small_sort/*.c utils/*.c\

all: $(NAME)

$(NAME): $(SRC) 
	@cd $(SUB_DIR) && $(MAKE) -s
	@gcc -o $(NAME) $(FLAGS) $(SRC) $(SUB_DIR)/$(SUB_DIR).a $(SUB_DIR_M)
	@echo "compiled!"

bonus: $(NAME)

clean:
	@rm -f $(NAME)

clean_libft:
	@cd $(SUB_DIR) && $(MAKE) -s clean
	
fclean:
	@rm -f $(NAME)
	@cd $(SUB_DIR) && $(MAKE) -s fclean

re: fclean all