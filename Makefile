# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 00:57:35 by ybouchra          #+#    #+#              #
#    Updated: 2023/03/24 00:00:38 by ybouchra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc -Wall -Wextra -Werror
AR = ar rc
RM = rm -f


FILES = utils/ft_strchr.c \
	utils/ft_strdup.c \
	utils/ft_strjoin.c \
	utils/ft_strlen.c \
	utils/ft_puterror.c \
	utils/get_next_line.c \
	utils/ft_strcmp.c \
	valid_path.c \
	so_long.c

OBJS = $(FILES:.c=.o)

all : $(NAME) 

$(NAME) : $(OBJS)
	@$(CC) $^ -o $@
	@echo "$@ created"

%.o : %.c includes/so_long.h
	@$(CC) -c $< -o $@ 

clean :
	@$(RM) $(OBJS) $(S_OBJ)
	@echo "object files removed"

fclean : clean
	@$(RM) $(NAME)
	@echo "delete all"

re : fclean all
