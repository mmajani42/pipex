# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 07:14:59 by mmajani           #+#    #+#              #
#    Updated: 2023/02/23 10:05:42 by mmajani          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

SRCS		=	errors.c		\
				paths.c			\
				pipexbonus.c
				
HEADS		= $(shell find . -type f -name *.h)

OBJS 		= $(SRCS:.c=.o)

CFLAGS		= -Wall -Wextra

all:  maker $(NAME)

$(NAME):	$(OBJS) libft/libft.a
			ln -sf libft/libft.a
			$(CC) $(CFLAGS) $(OBJS) libft.a -o $(NAME)
			
%.o: 		%.c $(INCLUDE) $(HEADS) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

maker:
		${MAKE} -C libft

clean:
		$(RM) $(OBJS) libft.a gnl.o

fclean: clean
		$(RM) $(NAME)
		${MAKE} fclean -C libft
		
re:		fclean all

.PHONY:	all clean fclean re
