/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:20:48 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/27 20:21:07 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**strdup_table(char **env)
{
	int		i;
	char	**table;

	if (env == NULL)
		return (NULL);
	i = ft_len_of_table_2(env);
	table = (char **)malloc(sizeof(char *) * (i + 1));
	if (!table)
		return (NULL);
	table[i] = 0;
	i = -1;
	while (env[++i])
	{
		table[i] = ft_strdup(env[i]);
		if (!table[i])
			return (NULL);
	}
	return (table);
}

void	handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_data.r_error = 1;
}

void	handler2(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	g_data.r_error = 1;
}
