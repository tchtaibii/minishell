/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   pipe_help_split.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ybouali <ybouali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/19 08:42:24 by ybouali		   #+#	#+#			 */
/*   Updated: 2022/03/25 19:02:49 by ybouali		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	for_ft_cnofw(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		if (str[i] == 34)
		{
			i++;
			while (str[i])
				if (str[i++] == 34)
					break ;
		}
		else if (str[i] == 39)
		{
			i++;
			while (str[i])
				if (str[i++] == 39)
					break ;
		}
		i++;
	}
	return (i);
}

char	**ft_cnofw(char *str, int *h, char c)
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
		i += for_ft_cnofw(&str[i], c);
	}
	*h = size;
	table = (char **)malloc(sizeof(char *) * (size + 1));
	if (!table)
	{
		free(table);
		return (NULL);
	}
	table[size] = 0;
	return (table);
}
