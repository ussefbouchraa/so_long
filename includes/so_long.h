/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:05:16 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/24 04:30:43 by ybouchra         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif 

//part 1

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		fd;
	int		x;
	int		y;
	int		j;
	int		p;
	int		c;
	int		e;
	int		width;
	int		hight;
	char	**map;
	char	**map2;
	char	*line;
}	t_vars;


// part one
size_t	ft_strlen(const char *str);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
void    ft_puterror(char *s);
char	*ft_strrchr(const char *s, int c);

//part two
void valid_path(t_vars *var);
void free_map(char **map);
void print_map(char **map);
int ft_strcmp(char *s1, char *s2);
void    clear_vars(t_vars *var, int err);
void map_border(t_vars *var);

#endif 
