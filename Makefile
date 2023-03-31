NAME = so_long

CC = cc -Wall -Wextra -Werror

RM = rm -f

MLX_FLG = -lmlx -framework OpenGL -framework AppKit

UTILS =  utils/ft_puterror.c utils/ft_strchr.c utils/ft_strcmp.c utils/ft_strdup.c \
	utils/ft_strjoin.c utils/ft_strlen.c utils/get_next_line.c srcs/so_long_utils.c

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
	@echo "compiling $< ...Done!"

clean :
	@$(RM) $(SOBJ) $(UOBJ)
	@echo "removed object files"

fclean : clean
	@$(RM) $(NAME)
	@echo "removed so_long"

re : fclean all
