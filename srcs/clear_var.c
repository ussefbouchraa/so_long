/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:23:19 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/24 04:49:39 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clear_vars(t_vars *var, int err)
{
	if (var->line != NULL)
		free(var->line);
	if (var->map2 != NULL)
		free_map(var->map2);
	if (var->map != NULL)
		free_map(var->map);
	if (err != 0)
		ft_puterror("Error : invalid map\n");
	else
		exit(0);
}
