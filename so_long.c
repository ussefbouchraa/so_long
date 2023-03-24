/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:06:10 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/24 00:07:32 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void print_map(char **map)
{
	while (*map)
		printf("%s\n", *map++);
}
void map_border(t_vars *var)
{
	var->width = (int)ft_strlen(var->map[var->x]);
	
	while(var->map[var->x])
	{   
			if(var->map[var->x][0]!= '1' || var->map[var->x][var->width - 1] != '1' )
				{
					ft_puterror("Error : invalid map\n");
				}
	   var->x++;
	}      
	while(var->width > var->y)
	{
		if(var->map[0][var->y] != '1' || var->map[var->hight - 1][var->y] != '1') 
			{
				ft_puterror("Error : invalid map\n");
			}
	var->y++;
	}
		var->x = 0;
		var->y = 0;
}


void map_chars(t_vars *var)
{
	while(var->map[var->x])
	{
		if(var->map[var->x] && ((int)ft_strlen(var->map[var->x]) != var->width))
		{
			ft_puterror("Error : invalid map\n");
		} 
		var->y = 0;
		while(var->map[var->x][var->y])
		{
			if(var->map[var->x][var->y] == 'P')
			var->p++;
			else if(var->map[var->x][var->y] == 'C')
			var->c++;
			else if(var->map[var->x][var->y] == 'E')
			   var->e++;
			else if(var->map[var->x][var->y] != '1' && var->map[var->x][var->y] != '0')
			ft_puterror("Error : invalid map\n");
			var->y++;
		}
		var->x++;
	}
	if (var->c == 0 || var->e != 1 || var->p != 1)
		ft_puterror("Error : invalid map\n");
}
void init_vars(t_vars *var)
{
	var->fd = 0;
	var->x = 0;
	var->y = 0;
	var->j = 0;
	var->p = 0;
	var->c = 0;
	var->e = 0;
	var->width = 0;
	var->hight = 0;
	var->map = NULL;
	var->map2 = NULL;
	var->line = NULL;
}


void check_map(char *av, t_vars *var)
{
	var->fd = open(av, O_RDONLY);
	var->map = (char **)malloc((var->hight + 1) * sizeof(char *));
	if (!var->map)
		ft_puterror("Error : invalid map\n");
	while (var->j < var->hight)
		var->map[var->j++] = get_next_line(var->fd);
	var->map[var->j] = NULL;
	close(var->fd);
   if(var->map)
   {
		map_border(var);
		map_chars(var);
		valid_path(var);
   } 
   else
   {
		ft_puterror("Error : invalid map\n");
		free_map(var->map);
   } 
}

void    check_extention(char *av)
{
	if (ft_strcmp(ft_strrchr(av, '.'), ".ber"))
		ft_puterror("Error : Wrong extention\n");
}

void lek() { system("leaks so_long");}

int main(int ac, char **av)
{
	t_vars var;
	init_vars(&var);

	// atexit(lek);
	if(ac == 2)
	{
		check_extention(av[1]);
		var.fd = open(av[1], O_RDONLY,0777);
		if(var.fd == -1 )
			ft_puterror("Error : fd not found\n");
		// var.line = get_next_line(var.fd);
		while ((var.line = get_next_line(var.fd)) != NULL)
		{ 
			var.hight++;
			free(var.line);
		}
		if(var.hight == 0 )
			ft_puterror(" Error lines empty\n");    
		close(var.fd);
		check_map(av[1], &var);
	}
	else
		return (1);
}
