# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 19:02:48 by oipadeol          #+#    #+#              #
#    Updated: 2021/12/15 22:14:05 by oipadeol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# # _*_ MakeFile _*_

NAME = libft.a

SRC = 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalpha.c ft_isalnum.c ft_isascii.c\
		ft_isdigit.c ft_isascii.c ft_strlen.c ft_memset.c ft_memcpy.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
		ft_strdup.c ft_substr.c ft_strjoin.c ft_isprint.c ft_memmove.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_strcmp.c\
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
		ft_lstmap.c ft_lstelem.c

OBJ = obj_files

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	@$(MAKE) -s lib
	@echo "library created."

lib: objects
	ar -cr $(NAME) $(OBJ)/*.o
	
objects:
	gcc -c $(FLAGS) $(SRC)
	@mv *.o $(OBJ)

clean:
	@rm -f $(OBJ)/*.o
	@echo "*.o files deleted"

fclean:
	@$(MAKE) clean -s
	@rm -f $(NAME)
	@echo "library deleted."

re: fclean all