# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 12:05:23 by eemuston          #+#    #+#              #
#    Updated: 2023/02/22 18:16:13 by eemuston         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CLIENT = client

SERVER = server

FLAGS = -Wall -Werror -Wextra

HEADER = -I minitalk.h

C_SRC = client.c 

S_SRC = server.c

C_OBJ = client.o 

S_OBJ = server.o

all: $(NAME)

%.o:	%.c
		cc $(FLAGS) -c $< -o $@

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT): $(C_OBJ)
		$(MAKE) -C ./libft
		cc $(C_SRC) -o $(CLIENT) $(FLAGS) $(HEADER) libft/libft.a
$(SERVER): $(S_OBJ)
		$(MAKE) -C ./libft
		cc $(S_SRC) -o $(SERVER) $(FLAGS) $(HEADER) libft/libft.a
clean:
		$(MAKE) clean -C ./libft
		rm -f $(C_OBJ) $(S_OBJ)
fclean: clean
		$(MAKE) fclean -C ./libft
		rm -f $(SERVER) $(CLIENT) clean
re: fclean all