# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 15:24:55 by jrivoire          #+#    #+#              #
#    Updated: 2021/02/18 14:26:05 by jrivoire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

CC				=	gcc

OBJS			=	$(SRCS:.c=.o)

IDIR			=	headers/

SRCS			= 	char/ft_isalnum.c \

RM				=	rm -f

FLAGS			=	-Wall -Wextra -Werror

.c.o:
	$(CC) $(FLAGS) -I$(IDIR) -c $< -o $(<:.c=.o)

$(NAME):	make_lib $(OBJS)
	ar rcs $(NAME) $(OBJS)

all:		$(NAME)

make_lib:
	@make libft.a -C ./libft

clean:
	$(RM) $(OBJS)
	@make clean -C ./libft

fclean: 	clean
	$(RM) $(NAME)
	@make fclean -C ./libft

re:			fclean all

.PHONY:	all clean fclean re
