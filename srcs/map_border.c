/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:20:19 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/26 23:58:46 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void map_border(t_vars *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	var->width = (int)ft_strlen(var->map[x]);
	while(var->map[x])
	{
		if((int)ft_strlen(var->map[x]) != var->width)
			clear_vars(var, 1);
		if(var->map[x][0]!= '1' 
			|| var->map[x][var->width - 1] != '1' )
			clear_vars(var, 1);
		x++;
	}
	while(var->width > y)
	{
		if(var->map[0][y] != '1' 
			|| var->map[var->hight - 1][y] != '1')
			clear_vars(var, 1);
		y++;
	}
}
