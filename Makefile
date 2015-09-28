# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elivet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/11 14:09:39 by elivet            #+#    #+#              #
#    Updated: 2014/03/23 12:13:11 by elivet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= lem-in

FLAGS= -Wall -Wextra -Werror

SRC= main.c get_next_line.c ft_strnew.c ft_strlen.c ft_strcpy.c ft_strjoin.c \
	ft_strclr.c ft_atoi.c ft_nospace.c ft_isdigit.c ft_strsplit.c stock.c \
	ft_strcmp.c ft_strsub.c ft_strdup.c link.c ft_putendl.c ft_putstr.c \
	ft_putchar.c ft_itoa.c ft_sizeofint.c ant.c way.c error.c take.c \
	ft_lstnew.c ft_lstaddtail.c tab_to_list.c ft_strequ.c inside.c


OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC) -g
	gcc -o $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
