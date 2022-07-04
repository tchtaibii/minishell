/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   handle_err_help.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ybouali <ybouali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/26 15:00:53 by ybouali		   #+#	#+#			 */
/*   Updated: 2022/03/27 15:22:45 by ybouali		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_double_sengle(int *j, char *var, int ds)
{
	*j += 1;
	if (var[*j] == ds)
		return (-1);
	while (var[*j] && var[*j] != ds)
	{
		if (var[*j] == ds)
			break ;
		if (ft_isalnum(var[*j]) == 0 || var[*j] != '_')
			return (-1);
		*j += 1;
	}
	*j += 1;
	return (0);
}

int	help_err22(char *var, int j)
{
	if (var[j] == 34)
	{
		if (check_double_sengle(&j, var, 34) == -1)
			return (-1);
	}
	if (var[j] == 39)
	{
		if (check_double_sengle(&j, var, 39) == -1)
			return (-1);
	}
	return (j);
}

static int	help_err(char *var, int boolean)
{
	static int	j;
	int			r;

	if (var[0] == 34 || var[0] == 39)
		if (ft_isdigit(var[1]))
			return (1);
	j = 0;
	while (var[j] != '\0')
	{
		if (boolean == 1 && var[j] == 61)
			return (0);
		if (var[j] == 34 || var[j] == 39)
		{
			r = help_err22(var, j);
			if (r == 1)
				return (1);
		}
		else if (ft_isalnum(var[j]) == 0 && var[j] != '_')
			return (1);
		j++;
	}
	return (0);
}

int	ft_handle_export_err(char **vars, int boolean)
{
	int	i;

	i = -1;
	while (vars[++i])
	{
		if (ft_isdigit(vars[i][0]))
			return (1);
		else
		{
			if (help_err(vars[i], boolean) == 1)
				return (1);
		}
	}
	return (0);
}
