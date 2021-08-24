# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/24 13:26:11 by lchaineu          #+#    #+#              #
#    Updated: 2021/08/24 13:52:23 by lchaineu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC						=		gcc
FLAGS			=		-Wall -Wextra -Werror
INC				=		./inc/
LIBFT_PATH		=		./Lib19/

CFLAGS			= 		-I$(LIBFT_PATH)inc/ -I $(INCL) $(FLAGS)

LINKS			=		-L $(LIBFT_PATH) -lft

######NAME######

NAME_SERVER		=		server
NAME_CLIENT		=		client

######PATH######

SRCS_PATH		=		srcs/

SRCS_SERVER		=		server.c

SRCS_CLIENT		=		client.c

SRCS_SERVER2	=		$(addprefix $(SRCS_PATH), $(SRCS_SERVER)) 

SRCS_CLIENT2	=		$(addprefix $(SRCS_PATH), $(SRCS_CLIENT))

OBJ_SERVER		=		$(SRCS_SERVER2:.c=.o)
OBJ_CLIENT		=		$(SRCS_CLIENT2:.c=.o)

######RULES######

all : libs $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER) : libs $(OBJ_SERVER)
		@$(CC) -o $(NAME_SERVER) $(OBJ_SERVER) $(CFLAGS) $(LINKS)

$(NAME_CLIENT) : libs $(OBJ_CLIENT)
		@$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(CFLAGS) $(LINKS)

clean:
		@/bin/rm -rf $(OBJ_SERVER) $(OBJ_CLIENT)
		@make -C $(LIBFT_PATH) clean

fclean: clean
		@$(RM) $(NAME_SERVER) $(NAME_CLIENT)
		@/bin/rm -rf $(LIBFT_PATH)libft.a

libs:
		@make -C $(LIBFT_PATH)

re: fclean all

.PHONY: all re clean fclean