/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_err3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:40:20 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/28 01:46:45 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_count_withespace(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')))
		i++;
	return (i);
}

int	line_without(char *line, int booleen, int skep)
{
	int	i;

	i = 0;
	i = skep_whitespace(line);
	if (booleen)
	{
		i += skep;
		i += skep_whitespace(&line[i]);
	}
	return (i);
}

int	help_check_for_err(char *line, int len, int boolean)
{
	char	**vars;

	vars = NULL;
	if (line[line_without(line, 1, 5)] == '\0')
		return (0);
	vars = ft_pipe_split(&line[line_without(line, 1, len)], ' ');
	if (ft_handle_export_err(vars, boolean) == 1)
	{
		ft_free_2d_table(vars);
		return (1);
	}
	ft_free_2d_table(vars);
	return (0);
}

int	ft_handle_err(char *line)
{
	int	return_check;

	return_check = 0;
	if (handle_pipe(ft_dup_line_for_pipe(line)))
		return (1);
	if (ft_handle_redir_error \
	(ft_dup_line_for_pipe(&line[skep_whitespace(line)])))
		return (1);
	if (ft_strncmp(&line[line_without(line, 0, 0)], "export", 6) == 0)
	{
		return_check = help_check_for_err(line, 6, 1);
		if (return_check == 0)
			return (0);
		if (return_check == 1)
			return (1);
	}
	if (ft_strncmp(&line[line_without(line, 0, 0)], "unset", 5) == 0)
	{
		return_check = help_check_for_err(line, 5, 0);
		if (return_check == 0)
			return (0);
		if (return_check == 1)
			return (1);
	}
	return (0);
}
