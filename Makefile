# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 19:08:06 by hlachhab          #+#    #+#              #
#    Updated: 2024/09/21 00:56:38 by hlachhab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRSC_SERVER:.c=.o)
OBJS_CLIENT = $(SRSC_CLIENT:.c=.o)


all: $(CLIENT) $(SERVER)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(SRCS_CLIENT) -o $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(SRCS_SERVER) -o $(SERVER)

clean:
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
		$(RM) $(CLIENT) $(SERVER)

re: fclean all
