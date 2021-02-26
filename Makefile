# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 15:24:55 by jrivoire          #+#    #+#              #
#    Updated: 2021/02/26 19:21:46 by jrivoire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

CC				=	gcc

OBJS			=	$(SRCS:.c=.o)

IDIR			=	headers/

SRCS			= 	ft_printf.c \
					string_parser.c \
					conversion_parser.c \
					converting_function.c \
					\
					converters/base_converter.c \
					converters/char_converter.c \
					converters/int_converters.c \
					converters/ptn_converter.c \
					converters/str_converter.c \
					\
					utils/printf_utils.c \
					utils/ft_atoi.c \
					utils/ft_isdigit.c \
					utils/ft_putstr_fd.c \
					utils/ft_putchar_fd.c \
					utils/ft_strchr.c \
					utils/ft_strdup.c \
					utils/ft_strjoin.c \
					utils/ft_strlen.c \
					utils/ft_substr.c \
					utils/ft_uitoa_base.c \
					utils/string_writer.c

RM				=	rm -f

FLAGS			=	-Wall -Wextra -Werror

.c.o:
	$(CC) $(FLAGS) -I$(IDIR) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
