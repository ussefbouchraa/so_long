/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 02:28:05 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/31 02:03:18 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	fill_map(char **map, int x, int y)
{
	int	ret;

	ret = 0;
	if (map[x][y + 1] == 'C' || map[x][y + 1] == 'E' || map[x][y + 1] == '0')
	{
		map[x][y + 1] = 'P';
		ret++;
	}
	if (map[x][y - 1] == 'C' || map[x][y - 1] == 'E' || map[x][y - 1] == '0')
	{
		map[x][y - 1] = 'P';
		ret++;
	}
	if (map[x + 1][y] == 'C' || map[x + 1][y] == 'E' || map[x + 1][y] == '0')
	{
		map[x + 1][y] = 'P';
		ret++;
	}
	if (map[x - 1][y] == 'C' || map[x - 1][y] == 'E' || map[x - 1][y] == '0')
	{
		map[x - 1][y] = 'P';
		ret++;
	}
	return (ret);
}

void	check_element(t_vars *var)
{
	int	x;

	x = 0;
	while (var->map2[x])
	{
		if (ft_strchr(var->map2[x], 'E') 
			|| ft_strchr(var->map2[x], 'C'))
			clear_vars(var, 1);
		x++;
	}
	free_map(var->map2);
	var->map2 = NULL;
}
void    dup_map(t_vars *var)
{
	int x;

	x = -1;
	var->map2 = malloc(sizeof(char *) * var->hight + 1);
	if (!var->map2)
		clear_vars(var, 1);
	while (var->map[++x])
		var->map2[x] = ft_strdup(var->map[x]);
	var->map2[x] = NULL;
}
void    valid_path(t_vars *var)
{
	int	x;
	int	y;
	
	x = 0;
	dup_map(var);
	while(var->map2[x])
	{
		y = 0;
		while (var->map2[x][y] )
		{
			if(var->map2[x][y] == 'P')
			{
				if (fill_map(var->map2, x, y) )
				{
					x = 0;
					y = 0;
				}
			}
			y++;
		}
		x++;
	}
	check_element(var);
}

