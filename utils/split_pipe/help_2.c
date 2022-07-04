/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:48:22 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/28 01:54:38 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	help_norm_1(char *str, int *n)
{
	str++;
	*n += 1;
	while (*str)
	{
		if (*str == 34)
			break ;
		str++;
		*n += 1;
	}
}

static void	help_norm_2(char *str, int *n)
{
	str++;
	n += 1;
	while (*str)
	{
		if (*str == 39)
			break ;
		str++;
		n += 1;
	}
}

static int	for_ft_ccofw(char *str, char c)
{
	static int	n;

	n = 0;
	while (*str && *str != c)
	{
		if (*str == 34)
			help_norm_1(str, &n);
		else if (*str == 39)
			help_norm_2(str, &n);
		str++;
		n++;
	}
	return (n);
}

char	**ft_ccofw(char *str, char c, int *f, char **table)
{
	int	n;
	int	i;
	int	h;

	h = 0;
	i = 0;
	while (*str && h < *f)
	{
		while (*str && *str == c)
			str++;
		n = for_ft_ccofw(str, c);
		table[h] = (char *)malloc(sizeof(char) * (n + 1));
		if (!table)
		{
			free(table);
			return (NULL);
		}
		h++;
	}
	return (table);
}
