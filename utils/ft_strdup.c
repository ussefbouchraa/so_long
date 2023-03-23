/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 03:11:23 by ybouchra          #+#    #+#             */
/*   Updated: 2023/03/16 19:19:06 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc((sizeof(char) * ft_strlen(s1)) + 1);
	if (!new)
	{
		return (NULL);
	}
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
