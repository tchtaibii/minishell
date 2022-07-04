/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:07:17 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/27 20:08:29 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	**ft_cnumberofw(char const *str, int *h, char c)
{
	int		size;
	int		i;
	char	**table;

	size = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			size++;
		while (str[i] && str[i] != c)
			i++;
	}
	*h = size;
	table = (char **)malloc(sizeof(char *) * (size + 1));
	if (!table)
	{
		free(table);
		return (NULL);
	}
	return (table);
}

static char	**ft_cnumberofc(char const *str, char c, int *f, char **table)
{
	int		n;
	int		i;
	int		h;

	h = 0;
	i = 0;
	while (*str && h < *f)
	{
		n = 0;
		while (*str && *str == c)
			str++;
		while (*str && *str != c)
		{
			str++;
			n++;
		}
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

static void	ft_stock_tab(char **table, int soft, char const *str, char c)
{
	int		i;
	int		j;
	int		m;

	m = 0;
	i = 0;
	while (i < soft)
	{
		while (str[m] && str[m] == c)
			m++;
		j = 0;
		while (str[m] && str[m] != c)
		{
			table[i][j] = str[m];
			j++;
			m++;
		}
		table[i][j] = '\0';
		i++;
	}
	table[i] = 0;
}

char	**ft_split(char *str, char c)
{
	char	**table;
	int		l;

	if (str == NULL)
		return (NULL);
	l = 0;
	table = ft_cnumberofw(str, &l, c);
	if (!table)
		return (NULL);
	table = ft_cnumberofc(str, c, &l, table);
	if (!table)
		return (NULL);
	ft_stock_tab(table, l, str, c);
	return (table);
}
