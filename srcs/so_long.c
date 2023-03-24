/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:06:10 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/24 05:30:24 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void print_map(char **map)
{
	while (*map)
		printf("%s\n", *map++);
}

int	is_element_of_map(char c)
{
	if (c == 'E' || c == 'P' || c == '0')
		return (1);
	else if (c == 'C' || c == '1')
		return (1);
	return (0);
}

void	map_chars(t_vars *var)
{
	int	x;
	int	y;

	x = -1;
	while(var->map[++x])
	{
		y = -1;
		while(var->map[x][++y])
		{
			if (is_element_of_map(var->map[x][y]))
			{
				if(var->map[x][y] == 'P')
					var->p++;
				else if(var->map[x][y] == 'C')
					var->c++;
				else if(var->map[x][y] == 'E')
					var->e++;
			}
			else
				clear_vars(var, 1);
		}
	}
	if (var->c == 0 || var->e != 1 || var->p != 1)
		clear_vars(var, 1);
}

void	check_map(char *av, t_vars *var)
{
	int	j;

	j = 0;
	var->fd = open(av, O_RDONLY);
	var->map = (char **)malloc((var->hight + 1) * sizeof(char *));
	if (!var->map)
		ft_puterror("Error : invalid map\n");
	while (j < var->hight)
		var->map[j++] = get_next_line(var->fd);
	var->map[j] = NULL;
	close(var->fd);
	map_border(var);
	map_chars(var);
	// valid_path(var);
	// play_game(var);
}

void    check_extention(char *av)
{
	if (ft_strcmp(ft_strrchr(av, '.'), ".ber"))
		ft_puterror("Error : Wrong extention\n");
}

void lek() { system("leaks so_long");}

int main(int ac, char **av)
{
	t_vars	var;

	// init_vars(&var);
	memset(&var, 0, sizeof(t_vars));
	if(ac == 2)
	{
		check_extention(av[1]);
		var.fd = open(av[1], O_RDONLY,0777);
		if(var.fd == -1 )
			ft_puterror("Error : fd not found\n");
		var.line = get_next_line(var.fd);
		while (var.line)
		{
			var.hight++;
			free(var.line);
			var.line = get_next_line(var.fd);
		}
		if(var.hight == 0 )
			ft_puterror("Error : invalid map\n");
		close(var.fd);
		check_map(av[1], &var);
	}
	else
		return (1);
}
