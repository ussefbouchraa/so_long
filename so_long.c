/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:06:10 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/22 02:16:04 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void print_map(char **map)
{
    while (*map)
        printf("%s\n", *map++);
}
void map_border(c_vars *var)
{
    var->width = (int)ft_strlen(var->map[var->x]);
    
    while(var->map[var->x])
    {   
            if(var->map[var->x][0]!= '1' || var->map[var->x][var->width - 1] != '1' )
                {
                    ft_puterror("Error Border (Left | Right)\n");
                    break;
                }
       var->x++;
    }      
    while(var->width > var->y)
    {
        if(var->map[0][var->y] != '1' || var->map[var->hight - 1][var->y] != '1') 
            {
                ft_puterror("Error Border(Top | Bottom)\n");
                break;
            }
    var->y++;
    }
        var->x = 0;
        var->y = 0;
}


void map_chars(c_vars *var)
{
    while(var->map[var->x])
    {
        if(var->map[var->x] && ((int)ft_strlen(var->map[var->x]) != var->width))
        {
            ft_puterror("Error lines not equals\n");
            break;
        } 
        var->y = 0;
        while(var->map[var->x][var->y])
        {
            if(var->map[var->x][var->y] == 'p')
            var->p++;
            else if(var->map[var->x][var->y] == 'c')
            var->c++;
            else if(var->map[var->x][var->y] == 'e')
               var->e++;
            else if(var->map[var->x][var->y] != '1' && var->map[var->x][var->y] != '0')
            ft_puterror("Error nbr incorrect");
            var->y++;
        }
        var->x++;
    }
    if (var->c == 0 || var->e != 1 || var->p != 1)
          ft_puterror("Error caractere P or E or C \n");
}
void init_vars(c_vars *var)
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


void check_map(char *av, c_vars *var)
{
    var->fd = open(av, O_RDONLY);
    var->map = (char **)malloc((var->hight + 1) * sizeof(char *));
    if (!var->map)
        ft_puterror(" Error Allocation failed");
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
    ft_puterror("Error empty_map");
    free_map(var->map);
   } 
}
int main(int ac, char **av)
{
    c_vars var;
    init_vars(&var);
    
    if(ac == 2)
    {
    var.fd = open(av[1], O_RDONLY,0777);
    if(var.fd == -1 )
        ft_puterror("Error fd not found 1 !");
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
    printf("Error ");
  
}
