# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amejia <amejia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 14:12:43 by amejia            #+#    #+#              #
#    Updated: 2023/04/03 22:47:13 by amejia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = philo

NAME_DEBUG = philo_debug

SRCS = ft_atoi.c main.c 

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

bonus: $(NAME_BONUS)

clean: 
	rm -f $(OBJS) $(OBJS)

fclean: clean
	rm -f $(NAME) $(NAME_DEBUG) 
	
VS_debug: CFLAGS += -D DEBUG=1
VS_debug: $(NAME_DEBUG)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(NAME_DEBUG): $(OBJS)
	$(CC) $(CFLAGS) -fdiagnostics-color=always -g -o $@

re: fclean all

.PHONY: all clean fclean re VS_debug 
