/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 02:28:05 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/25 03:28:52 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int	is_path(char x)
// {
// 	return (x == 'C' || x == '0');
// }

int fill_map(char **map, int x, int y)
{
	int	ret;

	ret = 0;
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
	return (ret);
}

void	check_for_exit(t_vars *var)
{
	int x;

	x = 0;
	while (var->map2[x])
	{
		if (ft_strchr(var->map2[x], 'E') 
			|| ft_strchr(var->map2[x], 'C'))
			clear_vars(var);
		x++;
	}
}

void    valid_path(t_vars *var)
{
	int	x;
	int	y;
	
	x = 0;
	while(var->map2[x])
	{
		y = 0;
		while (var->map2[x][y])
		{
			if(var->map2[x][y] == 'P')
			{
				if (fill_map(var->map2, x, y) != 0)
				{
					x = 0;
					y = 0;
				}
			}
			y++;
		}
		x++;
	}
	check_for_exit(var);
}
