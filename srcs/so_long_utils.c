/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:14:04 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/31 02:29:59 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_moves(t_vars *var, int xx, int yy)
{
	if (var->map[xx][yy] != '1')
	{
		if (var->map[xx][yy] != 'E')
		{
			if (var->map[xx][yy] == 'C')
				var->c--;
			var->map[xx][yy] = 'P';
			var->map[var->x][var->y] = '0';
			var->moves++;
			put_moves(var->moves);
		}
		if (var->map[xx][yy] == 'E' && var->c == 0)
		{
			var->moves++;
			put_moves(var->moves);
			ft_putstr("Congratulation ! you Won\n");
			clear_vars(var, 0);
		}
	}
}

void	put_image_to_window(t_vars *var, int y, int x)
{
	if (var->map[x][y] == 'P')
		mlx_put_image_to_window(var->mlx, var->win,
			var->img.hero, y * 50, x * 50);
	else if (var->map[x][y] == 'C')
		mlx_put_image_to_window(var->mlx, var->win,
			var->img.coin, y * 50, x * 50);
	else if (var->map[x][y] == 'E')
		mlx_put_image_to_window(var->mlx, var->win,
			var->img.door, y * 50, x * 50);
	else if (var->map[x][y] == '0')
		mlx_put_image_to_window(var->mlx, var->win,
			var->img.road, y * 50, x * 50);
	else if (var->map[x][y] == '1')
		mlx_put_image_to_window(var->mlx, var->win,
			var->img.wall, y * 50, x * 50);
}

void	display_map(t_vars *var)
{
	int	x;
	int	y;

	x = 0;
	while (var->map[x])
	{
		y = -1;
		while (var->map[x][++y])
			put_image_to_window(var, y, x);
		x++;
	}
}

void	init_images(t_vars *var)
{
	int	w;
	int	h;

	var->img.coin = mlx_xpm_file_to_image(var->mlx, "imgs/coin.xpm", &w, &h);
	if (!var->img.coin)
		clear_vars(var, 1);
	var->img.door = mlx_xpm_file_to_image(var->mlx, "imgs/door.xpm", &w, &h);
	if (!var->img.door)
		clear_vars(var, 1);
	var->img.hero = mlx_xpm_file_to_image(var->mlx, "imgs/hero.xpm", &w, &h);
	if (!var->img.hero)
		clear_vars(var, 1);
	var->img.road = mlx_xpm_file_to_image(var->mlx, "imgs/road.xpm", &w, &h);
	if (!var->img.road)
		clear_vars(var, 1);
	var->img.wall = mlx_xpm_file_to_image(var->mlx, "imgs/wall.xpm", &w, &h);
	if (!var->img.wall)
		clear_vars(var, 1);
}
