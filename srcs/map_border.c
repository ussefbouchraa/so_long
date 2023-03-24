/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:20:19 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/24 04:33:47 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void map_border(t_vars *var)
{
	var->width = (int)ft_strlen(var->map[var->x]);
	while(var->map[var->x])
	{
		if(var->map[var->x][0]!= '1' 
			|| var->map[var->x][var->width - 1] != '1' )
			clear_vars(var, 1);
		var->x++;
	}
	while(var->width > var->y)
	{
		if(var->map[0][var->y] != '1' 
			|| var->map[var->hight - 1][var->y] != '1')
			clear_vars(var, 1);
		var->y++;
	}
	var->x = 0;
	var->y = 0;
}
