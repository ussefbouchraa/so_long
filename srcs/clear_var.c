/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:23:19 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/31 02:10:25 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		free(map[i]);
		map[i] = NULL;
	}
	free(map);
	map = NULL;
}

void	destroy_images(t_vars *var)
{
	if (var->img.hero)
		mlx_destroy_image(var->mlx, var->img.hero);
	if (var->img.coin)
		mlx_destroy_image(var->mlx, var->img.coin);
	if (var->img.door)
		mlx_destroy_image(var->mlx, var->img.door);
	if (var->img.road)
		mlx_destroy_image(var->mlx, var->img.road);
	if (var->img.wall)
		mlx_destroy_image(var->mlx, var->img.wall);
}

void	clear_vars(t_vars *var, int msg)
{
	if (var->line)
		free(var->line);
	if (var->map2)
		free_map(var->map2);
	if (var->map)
		free_map(var->map);
	if (var->mlx)
	{
		destroy_images(var);
		if (var->win)
		{
			mlx_clear_window(var->mlx, var->win);
			mlx_destroy_window(var->mlx, var->win);
		}
	}
	if (msg == 1)
		ft_puterror("Error : invalid map\n");
	exit(0);
}
