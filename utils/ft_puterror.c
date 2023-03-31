/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:22:57 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/31 01:25:16 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    ft_putstr(char *s)
{
    while (*s)
        write(1, s++, 1);
}

void ft_puterror(char *s)
{
    while (*s)
        write(2, s++, 1);
    exit(1);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}

void    put_moves(int moves)
{
    ft_putstr("Moves : ");
    ft_putnbr(moves);
    ft_putstr("\n");
}
