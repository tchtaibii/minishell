/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_err2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:37:54 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/28 01:40:12 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	help_handle_pipe(char *line, int i)
{
	while (line[i])
	{
		if (line[i] == 124)
		{
			i++;
			i += skep_whitespace(&line[i]);
			if (line[i] == '\0' || line[i] == 124)
			{
				free(line);
				return (1);
			}
		}
		else
			i++;
	}
	free(line);
	return (0);
}

int	handle_pipe(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (1);
	i += skep_whitespace(line);
	if (line[i] == 124)
		return (1);
	return (help_handle_pipe(line, i));
}

int	handle_left(char *line, int i)
{
	i += skep_whitespace(&line[i]);
	if (line[i] == '\0' || line[i] == '>')
	{
		free(line);
		return (1);
	}
	else if (line[i++] == '<')
	{
		i += skep_whitespace(&line[i]);
		if (line[i] == '\0')
		{
			free(line);
			return (1);
		}
		else if (line[i] == '>' || line[i] == '<')
		{
			free(line);
			return (1);
		}
	}
	return (0);
}

int	handle_right(char *line, int i)
{
	i += skep_whitespace(&line[i]);
	if (line[i] == '\0' || line[i] == '<')
	{
		free(line);
		return (1);
	}
	else if (line[i++] == '>')
	{
		i += skep_whitespace(&line[i]);
		if (line[i] == '\0')
		{
			free(line);
			return (1);
		}
		else if (line[i] == '>' || line[i] == '<')
		{
			free(line);
			return (1);
		}
	}
	return (0);
}

int	ft_handle_redir_error(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '>')
		{
			if (handle_right(line, ++i))
				return (1);
			i++;
		}
		else if (line[i] == '<')
		{
			if (handle_left(line, ++i))
				return (1);
			i++;
		}
		else
			i++;
	}
	free(line);
	return (0);
}
