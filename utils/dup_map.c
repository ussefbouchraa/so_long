/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 02:37:20 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/25 03:01:47 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char **dup_map(char **map, int hight)
{
    char **map2;
    int j;

    j = -1;
    map2 = malloc(sizeof(char *) * hight + 1);
    if (!map2)
        return (NULL);

    while (map[++j])
        map2[j] = ft_strdup(map[j]);

    map2[j] = NULL;
    return (map2);
}
