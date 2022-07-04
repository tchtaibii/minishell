/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   handle_err.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ybouali <ybouali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/09 06:09:18 by ybouali		   #+#	#+#			 */
/*   Updated: 2022/03/27 15:04:43 by ybouali		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	skep_whitespace(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && ((src[i] >= 9 && src[i] <= 13) || src[i] == ' '))
		i++;
	return (i);
}

static int	help_stock_1(char *line, char *dup, int to, int *j)
{
	while (line[*j] != '\0' && line[*j] != to)
	{
		dup[*j] = 'y';
		*j += 1;
	}
	if (line[*j] == '\0' || line[*j] != to)
	{
		free(dup);
		return (0);
	}
	return (1);
}

static int	help_stock(char *line, char *dup, int to, int *j)
{
	dup[*j] = 'y';
	*j += 1;
	if (help_stock_1(line, dup, to, j) == 0)
		return (0);
	dup[*j] = 'y';
	*j += 1;
	return (1);
}

static char	*stock_new_pipe(char *line, char *dup)
{
	static int	i;
	int			j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == 34 || line[i] == 39)
		{
			if (line[i] == 34)
				j = help_stock(line, dup, 34, &i);
			else
				j = help_stock(line, dup, 39, &i);
			if (j == 0)
				return (NULL);
		}
		else
		{
			dup[i] = line[i];
			i++;
		}
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_dup_line_for_pipe(char *line)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(ft_strlen(line) + 1);
	if (!dup)
		return (NULL);
	return (stock_new_pipe(line, dup));
}
