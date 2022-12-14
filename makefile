# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 16:41:28 by mogonzal          #+#    #+#              #
#    Updated: 2022/12/20 18:41:55 by mogonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		so_long.a

HEADER = 	so_long.h

LIBFT = libft/libft.a


MLX = mlx/mlx.h

SRC	=		main.c \
			src/checker.c \
			src/map_check_1.c \
			src/map_check_2.c

# SRC_BNS	=	main.c

OBJ	=		$(SRC:.c=.o)

# OBJ_BNS	=	$(OBJ_BNS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -MMD

%.o: %.c
			$(CC) $(FLAGS) -Imlx -I mlx/mlx.h -c $< -o $@

RM		=	rm -f



#___________________________________________________________#

all:		mlx libft $(NAME)

mlx:
			@$(MAKE) -C mlx

libft:		
			@$(MAKE) -C ./libft all
			
$(NAME):	$(OBJ) $(LIBFT) $(MLX) $(HEADER)
			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(GNL)
			@echo "Compiling so_long"
			
clean:		
			$(RM) $(OBJ)
#			$(RM) $(OBJ_BNS)
			@echo "Clean done"

fclean:		clean
			$(RM) $(NAME)
#			$(RM) so_long_bonus
			$(MAKE) -C ./libft fclean
			$(MAKE) -C ./mlx clean
			$(RM) $(GNL) a.out
			@echo "FClean done"

re:			fclean all
			
.PHONY:		all libft clean fclean re