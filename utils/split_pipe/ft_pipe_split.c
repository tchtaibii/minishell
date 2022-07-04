/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_pipe_split.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ybouali <ybouali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/02/27 13:45:28 by ybouali		   #+#	#+#			 */
/*   Updated: 2022/03/25 19:03:25 by ybouali		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	help_norm_1(char *table, char *str, int *j, int *m)
{
	table[*j] = str[*m];
	*j += 1;
	*m += 1;
	while (str[*m])
	{
		if (str[*m] == 39)
			break ;
		table[*j] = str[*m];
		*j += 1;
		*m += 1;
	}
}

static void	help_norm_2(char *table, char *str, int *j, int *m)
{
	table[*j] = str[*m];
	*j += 1;
	*m += 1;
	while (str[*m])
	{
		if (str[*m] == 34)
			break ;
		table[*j] = str[*m];
		*j += 1;
		*m += 1;
	}
}

static void	for_ft_stock_tab(char *table, char *str, char c, int *m)
{
	static int		j;

	j = 0;
	while (str[*m] && str[*m] != c)
	{
		if (str[*m] == 34)
			help_norm_2(table, str, &j, m);
		else if (str[*m] == 39)
			help_norm_1(table, str, &j, m);
		table[j] = str[*m];
		j++;
		*m += 1;
	}
	table[j] = '\0';
}

static void	ft_stock_tab(char **table, int soft, char *str, char c)
{
	static int		i;
	static int		m;

	m = 0;
	i = 0;
	while (i < soft)
	{
		while (str[m] && str[m] == c)
			m++;
		for_ft_stock_tab(table[i], str, c, &m);
		i++;
	}
}

char	**ft_pipe_split(char *str, char c)
{
	char	**table;
	int		l;

	if (str == NULL)
		return (NULL);
	l = 0;
	table = ft_cnofw(str, &l, c);
	if (!table)
		return (NULL);
	table = ft_ccofw(str, c, &l, table);
	if (!table)
		return (NULL);
	ft_stock_tab(table, l, str, c);
	return (table);
}
