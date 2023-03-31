/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:05:16 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/31 02:32:33 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

//part 1
typedef struct s_img
{
	void	*hero;
	void	*wall;
	void	*coin;
	void	*door;
	void	*road;
}	t_img;

typedef struct s_vars
{
	t_img	img;
	void	*mlx;
	void	*win;
	int		moves;
	int		fd;
	int		x;
	int		y;
	int		c;
	int		e;
	int		p;
	int		width;
	int		hight;
	char	**map;
	char	**map2;
	char	*line;
}	t_vars;

// so_long Functions :
void	check_moves(t_vars *var, int xx, int yy);
void	init_images(t_vars *var);
void	map_border(t_vars *var);
void	valid_path(t_vars *var);
void	move_player(t_vars *var, int key);
void	clear_vars(t_vars *var, int msg);
void	free_map(char **map);
void	play_game(t_vars *var);
void	display_map(t_vars *var);

// utils functions :
size_t	ft_strlen(const char *str);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
void	ft_puterror(char *s);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *s);
void	put_moves(int moves);

#endif
