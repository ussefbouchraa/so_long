/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 05:50:30 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/31 01:29:18 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int close_window(t_vars *vars)
{
    clear_vars(vars, 0);
    exit(0);
}
int hook_func(int key, t_vars *var)
{
    var->x = 0;
    (void)var;

    if (key == 53)
        clear_vars(var, 0);
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
void check_moves(t_vars *var, int xx, int yy)
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
void move_player(t_vars *var, int key)
{
    int xx;
    int yy;

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


void    display_map(t_vars *var)
{
    int x;
    int y;

    x = 0;
    while (var->map[x])
    {
        y = 0;
        while (var->map[x][y])
        {
            if (var->map[x][y] == 'P')
                mlx_put_image_to_window(var->mlx, var->win, var->img.hero, y * 50, x * 50);
            else if (var->map[x][y] == 'C')
                mlx_put_image_to_window(var->mlx, var->win, var->img.coin, y * 50, x * 50);
            else if (var->map[x][y] == 'E')
                mlx_put_image_to_window(var->mlx, var->win, var->img.door, y * 50, x * 50);
            else if (var->map[x][y] == '0')
                mlx_put_image_to_window(var->mlx, var->win, var->img.road, y * 50, x * 50);
            else if (var->map[x][y] == '1')
                mlx_put_image_to_window(var->mlx, var->win, var->img.wall, y * 50, x * 50);
            y++;
        }
        x++;
    }
}
void    init_images(t_vars *var)
{
    int w;
    int h;

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

void    play_game(t_vars *var)
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
