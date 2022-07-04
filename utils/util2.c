/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:01:31 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/03/27 22:01:52 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_get_cmd(char **env, char *cmd)
{
	char	*tmp;
	char	*command;
	char	**paths;

	paths = ft_split(find_var(env, "PATH"), ':');
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
		{
			ft_free_2d_table(paths);
			return (command);
		}
		free(command);
		paths++;
	}
	return (NULL);
}

int	ft_check_nember_of_n(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ')
			return (0);
	}
	if (str[--i] == 'n')
		return (0);
	return (1);
}

int	ft_len_of_table_2(char **table)
{
	int	i;

	i = 0;
	while (table[i])
		i++;
	return (i);
}

size_t	len_of_withespace(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && ((line[i] >= 9 && line[i] <= 13) || line[i] == ' '))
		i++;
	return (i);
}
