# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segan <segan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 16:12:00 by segan             #+#    #+#              #
#    Updated: 2022/10/19 18:15:55 by segan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

NAME1 = client

CC = cc

CFLAGS = -Wall -Wextra -Werror -o

SERVER_SRCS = server.c

CLIENT_SRCS = client.c	ft_atoi.c

STATICLIB_PATH = ./ft_printf

STATICLIB_NAME = ftprintf

all : $(NAME) $(NAME1)

$(NAME) : $(SERVER_SRCS)
	make -C ft_printf
	$(CC) $(CFLAGS) $(NAME) $(SERVER_SRCS) -L$(STATICLIB_PATH) -l$(STATICLIB_NAME)

$(NAME1) : $(CLIENT_SRCS)
	$(CC) $(CFLAGS) $(NAME1) $(CLIENT_SRCS)

clean :
	make clean -C ft_printf

fclean :
	make fclean -C ft_printf
	rm -f $(NAME)
	rm -f $(NAME1)

re :
	make fclean
	make all

.PHONY : all clean fclean re
