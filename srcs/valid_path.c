/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 01:21:50 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/24 04:34:06 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void dup_map(t_vars *var)
{
	var->map2 = malloc(sizeof(char *) * (var->hight + 1));
	if (!var->map2)
		ft_puterror("Error\n");
	var->j = -1;
	while (var->map[++var->j])
		var->map2[var->j] = ft_strdup(var->map[var->j]);
	var->map2[var->j] = NULL;
}

void free_map(char **map)
{
	while (*map)
	{
		free(*map);
		*map = NULL;
	}
	free(map);
	map = NULL;
}

void convert_map(t_vars *var)
{
	while (var->j > 0)
	{
		var->x = 0;
		while (var->map2[var->x])
		{
			var->y = 0;
			while (var->map2[var->x][var->y])
			{
				if (var->map2[var->x][var->y] == 'P')
				{
					if (var->map2[var->x][var->y + 1] == 'C' || var->map2[var->x][var->y + 1] == '0' || var->map2[var->x][var->y + 1] == 'E')
						var->map2[var->x][var->y + 1] = 'P';
					if (var->map2[var->x][var->y - 1] == 'C' || var->map2[var->x][var->y - 1] == '0' || var->map2[var->x][var->y - 1] == 'E')
						var->map2[var->x][var->y - 1] = 'P';
					if (var->map2[var->x - 1][var->y] == 'C' || var->map2[var->x - 1][var->y] == '0' || var->map2[var->x - 1][var->y] == 'E')
						var->map2[var->x - 1][var->y] = 'P';
					if (var->map2[var->x + 1][var->y] == 'C' || var->map2[var->x + 1][var->y] == '0' || var->map2[var->x + 1][var->y] == 'E')
						var->map2[var->x + 1][var->y] = 'P';
				}
				var->y++;
			}
			var->x++;
		}
		var->j--;
	}
}

void valid_path(t_vars *var)
{
	dup_map(var);
	if (var->map2)
		var->j = var->hight * var->width;
	convert_map(var);

	print_map(var->map2);
	var->x = 0;
	while (var->map2[var->x])
	{
		var->y = 0;
		while (var->map2[var->x] && var->map2[var->x][var->y])
		{
			if (var->map2[var->x][var->y] == 'C' 
				|| var->map2[var->x][var->y] == 'E')
				clear_vars(var, 1);
			var->y++;
		}
		var->x++;
	}
}
