/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 01:21:50 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/22 02:16:25 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void dup_map(c_vars *var)
{
    var->map2 = malloc(sizeof(char *) * (var->hight + 1));
    if (!var->map2)
        ft_puterror("Error l'allocation failed\n");
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

void convert_map(c_vars *var)
{
    while (var->j > 0)
    {
        var->x = 0;
        while (var->map2[var->x])
        {
            var->y = 0;
            while (var->map2[var->x][var->y])
            {
                if (var->map2[var->x][var->y] == 'p')
                {
                    if (var->map2[var->x][var->y + 1] == 'c' || var->map2[var->x][var->y + 1] == '0' || var->map2[var->x][var->y + 1] == 'e')
                        var->map2[var->x][var->y + 1] = 'p';
                    if (var->map2[var->x][var->y - 1] == 'c' || var->map2[var->x][var->y - 1] == '0' || var->map2[var->x][var->y - 1] == 'e')
                        var->map2[var->x][var->y - 1] = 'p';
                    if (var->map2[var->x - 1][var->y] == 'c' || var->map2[var->x - 1][var->y] == '0' || var->map2[var->x - 1][var->y] == 'e')
                        var->map2[var->x - 1][var->y] = 'p';
                    if (var->map2[var->x + 1][var->y] == 'c' || var->map2[var->x + 1][var->y] == '0' || var->map2[var->x + 1][var->y] == 'e')
                        var->map2[var->x + 1][var->y] = 'p';
                }
                var->y++;
            }
            var->x++;
        }
        var->j--;
    }
}

void valid_path(c_vars *var)
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
            if (var->map2[var->x][var->y] == 'c' || var->map2[var->x][var->y] == 'e')
            {
                ft_puterror("Error invalid_path\n");
                free_map(var->map2);
                break;
            }
            var->y++;
        }
        var->x++;
    }
}