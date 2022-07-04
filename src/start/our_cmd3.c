/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_cmd3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:41:49 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/03/28 03:15:11 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	cd2(t_shell *cmd)
{
	if (ft_strncmp(cmd->args, ".", ft_strlen(cmd->args)) == 0)
	{
		chdir((const char *)".");
		g_data.r_error = 0;
		return ;
	}
	else if (ft_strncmp(cmd->args, "..", ft_strlen(cmd->args)) == 0)
	{
		chdir("..");
		g_data.r_error = 0;
		return ;
	}
	else
	{
		chdir(cmd->args);
		g_data.r_error = 0;
		return ;
	}
}

int	echo( t_shell *cmd)
{
	printf("%s", cmd->args);
	if (!cmd->option)
		printf("\n");
	g_data.r_error = 0;
	return (g_data.r_error);
}

void	t_export_print(void)
{
	int	k;
	int	stop;
	int	i;

	i = -1;
	while (g_data.env_copy[++i])
	{
		printf("declare -x ");
		k = -1;
		while (g_data.env_copy[i][++k])
		{
			printf ("%c", g_data.env_copy[i][k]);
			if (g_data.env_copy[i][k] == '=')
			{
				stop = 1;
				printf ("%c", (char )34);
			}
		}
		if (stop == 1)
			printf ("%c", (char )34);
		printf ("\n");
		stop = 0;
	}
}

int	env(void)
{
	int		i;

	if (!g_data.env_copy)
		return (1);
	i = -1;
	while (g_data.env_copy[++i])
		if (ft_strchr(g_data.env_copy[i], '='))
			printf("%s\n", g_data.env_copy[i]);
	g_data.r_error = 0;
	return (g_data.r_error);
}
