/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:23:19 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/29 07:05:39 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i++] = NULL;
	}
	free(map);
	map = NULL;
}
void clear_vars(t_vars *var , int msg)
{
	if (var->line)
		free(var->line);
	if (var->map2)
		free_map(var->map2);
	if (var->map)
		free_map(var->map);
	if (var->mlx)
	{
		if (var->win)
		{
			mlx_clear_window(var->mlx, var->win);
			mlx_destroy_window(var->mlx, var->win);
		}
		free(var->mlx);
	}
	if(msg == 1)	
		ft_puterror("Error : invalid map\n");
	exit(0);
}
