# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 17:10:59 by mmajani           #+#    #+#              #
#    Updated: 2022/09/13 10:03:39 by mmajani          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRCS		=	ft_bzero.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_memset.c \
				ft_strlen.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_memchr.c	\
				ft_strncmp.c \
				ft_memcmp.c	\
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c	\
				ft_substr.c	\
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c	\
				ft_itoa.c	\
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				get_next_line.c \
				get_next_line_utils.c
				
SRCS_B	=		ft_lstnew.c	\
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c	\
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c
				
HEADER		= libft.h

OBJS 		= $(SRCS:.c=.o)

OBJS_B		= $(SRCS_B:.c=.o)

CFLAGS		= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):	$(OBJS) $(HEADER)
			ar rcs $@ $(OBJS)

%.o: 		%.c $(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

bonus:		$(OBJS) $(OBJS_B) $(HEADER)
			ar rcs $(NAME) $(OBJS) $(OBJS_B)

clean:
		$(RM) $(OBJS) $(OBJS_B)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
