# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 16:41:28 by mogonzal          #+#    #+#              #
#    Updated: 2022/09/05 17:31:08 by mogonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	main.c

# SRC_BNS	=	main.c

OBJ	=	$(SRC:.c=.o)

# OBJ_BNS	=	$(OBJ_BNS:.c=.o)

CC		=	gcc

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

CFLAGS	=	-Wall -Wextra -Werror -MMD

RM		=	rm -f

HEADER = 	so_long.h

#___________________________________________________________#

all:		libft server client

libft:		
			@$(MAKE) -C ./libft all
			
server:		$(OBJ1) $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJ1) $(LIBFT) -o server
			@echo "Compiling server"

client:		$(OBJ2) $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJ2) $(LIBFT) -o client
			@echo "Compiling client"

bonus:		libft $(BNS_O1) $(BNS_O2) $(LIBFT)
			@$(CC) $(CFLAGS) $(BNS_O1) $(LIBFT) -o server_bonus
			@echo "Compiling server_bonus"
			@$(CC) $(CFLAGS) $(BNS_O2) $(LIBFT) -o client_bonus
			@echo "Compiling client_bonus"
			
clean:		
			$(RM) $(OBJ)
			$(RM) $(OBJ_BNS)
			@echo "Clean done"

fclean:		clean
			$(RM) server client
			$(RM) server_bonus client_bonus
			$(MAKE) -C ./libft fclean
			@echo "FClean done"

re:			fclean all
			
.PHONY:		all libft clean fclean re