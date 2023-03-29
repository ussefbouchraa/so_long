# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 00:57:35 by ybouchra          #+#    #+#              #
#    Updated: 2023/03/26 04:08:39 by ybouchra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

MLX_FLG = -lmlx -framework OpenGL -framework AppKit

UTILS =  utils/ft_puterror.c utils/ft_strchr.c utils/ft_strcmp.c utils/ft_strdup.c \
	utils/ft_strjoin.c utils/ft_strlen.c utils/get_next_line.c 


SRCS = srcs/so_long.c srcs/map_border.c srcs/clear_var.c srcs/valid_path.c \
	srcs/play_game.c

UOBJ = $(UTILS:.c=.o)

SOBJ = $(SRCS:.c=.o)

all : $(NAME) 

$(NAME) : $(UOBJ) $(SOBJ)
	@$(CC) $(MLX_FLG) $^ -o $@
	@echo "$@ created"

%.o : %.c includes/so_long.h
	@$(CC) -c $< -o $@ 

clean :
	@$(RM) $(SOBJ) $(UOBJ)
	@echo "object files removed"

fclean : clean
	@$(RM) $(NAME)
	@echo "delete all"

re : fclean all
