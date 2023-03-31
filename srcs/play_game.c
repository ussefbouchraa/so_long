/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 05:50:30 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/31 02:17:31 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_vars *vars)
{
	clear_vars(vars, 0);
	exit(0);
}

int	hook_func(int key, t_vars *var)
{
	if (key == 53)
		clear_vars(var, 0);
	var->x = 0;
	if (key == 124 || key == 123 || key == 125 || key == 126)
	{
		while (var->map[var->x])
		{
			var->y = 0;
			while (var->map[var->x][var->y])
			{
				if (var->map[var->x][var->y] == 'P')
				{
					move_player(var, key);
					return (1);
				}
				var->y++;
			}
			var->x++;
		}
	}
	return (0);
}

void	move_player(t_vars *var, int key)
{
	int	xx;
	int	yy;

	xx = var->x;
	yy = var->y;
	if (key == 126)
		check_moves(var, xx - 1, yy);
	if (key == 125)
		check_moves(var, xx + 1, yy);
	if (key == 123)
		check_moves(var, xx, yy - 1);
	if (key == 124)
		check_moves(var, xx, yy + 1);
	mlx_clear_window(var->mlx, var->win);
	display_map(var);
}

void	play_game(t_vars *var)
{
	var->width = 50 * var->width;
	var->hight = 50 * var->hight;
	var->mlx = mlx_init();
	if (!var->mlx)
		clear_vars(var, 1);
	init_images(var);
	var->win = mlx_new_window(var->mlx, var->width, var->hight, "so_long");
	if (!var->win)
		clear_vars(var, 1);
	display_map(var);
	mlx_key_hook(var->win, hook_func, var);
	mlx_hook(var->win, 17, 0, close_window, var);
	mlx_loop(var->mlx);
}
