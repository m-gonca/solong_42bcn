# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 16:41:28 by mogonzal          #+#    #+#              #
#    Updated: 2022/09/20 15:55:35 by mogonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		so_long.a

HEADER = 	so_long.h

SRC	=		main.c \
			src/checker.c \
			src/map_check.c

# SRC_BNS	=	main.c

OBJ	=		$(SRC:.c=.o)

# OBJ_BNS	=	$(OBJ_BNS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -MMD

%.o: %.c
			$(CC) $(FLAGS) -Imlx -I mlx/mlx.h -c $< -o $@

RM		=	rm -f

LIBFT = libft/libft.a

GNL = get_next_line/get_next_line.a

MLX = mlx/mlx.a

#___________________________________________________________#

all:		mlx libft getnextline $(NAME)

mlx:
			@$(MAKE) -C mlx

libft:		
			@$(MAKE) -C ./libft all

getnextline: ./getnextline/getnextline_utils.h
			@$(CC) $(CFLAGS) BUFFER ./getnextline/getnextline.c ./getnextline/getnextline_utils.c
			
$(NAME):	$(OBJ) $(LIBFT) $(GNL) $(MLX) $(HEADER)
			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(GNL)
			@echo "Compiling so_long"
			
clean:		
			$(RM) $(OBJ)
#			$(RM) $(OBJ_BNS)
			@echo "Clean done"

fclean:		clean
			$(RM) $(NAME)
#			$(RM) so_long_bonus
			$(MAKE) -C ./libft fclean
			$(MAKE) -C ./mlx fclean
			$(RM) $(GNL)
			@echo "FClean done"

re:			fclean all
			
.PHONY:		all libft clean fclean re