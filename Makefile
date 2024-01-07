# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 14:37:50 by rnunes-a          #+#    #+#              #
#    Updated: 2023/11/18 22:21:06 by rnunes-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

AR = ar rc

RM = rm -rf

CP = cp

all: $(NAME)

$(NAME): $(OBJS)
	$(AR)  $(NAME) $(OBJS)
	

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all
so:
	$(CC) $(FLAGS) $(SRCS)
		$(OBJS)
