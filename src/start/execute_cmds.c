/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:55:34 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/27 21:00:15 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_cmd(char *cmd, t_data *data)
{
	char	*tmp;
	char	*command;
	char	**paths;
	int		i;

	i = -1;
	paths = ft_split(find_var(data->env_copy, "PATH"), ':');
	if (cmd == NULL || paths == NULL)
		return (NULL);
	if (cmd[0] == '/' || cmd[0] == '.')
		return (ft_strdup(cmd));
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
		{
			ft_free_2d_table(paths);
			return (command);
		}
		free(command);
	}
	ft_free_2d_table(paths);
	return (NULL);
}

static char	**normal_args(t_shell *cmd, char *new_cmd)
{
	char	**args;
	int		j;
	int		i;
	char	**tmp;

	args = ft_split(cmd->args, ' ');
	if (!args)
		exit(ft_errors(NULL, NULL, MALLOC_ERROR));
	tmp = malloc(sizeof(char *) * (table_len(args) + 2));
	if (!tmp)
		exit(ft_errors(NULL, NULL, MALLOC_ERROR));
	j = 0;
	i = -1;
	tmp[0] = new_cmd;
	while (args[++i])
		tmp[++j] = ft_strdup(args[i]);
	tmp[j + 1] = 0;
	ft_free_2d_table(args);
	return (tmp);
}

char	**herdoc_is_here(t_shell *cmd, char *cmd_new)
{
	char	**args;

	args = (char **)malloc(sizeof(char *) * 3);
	if (!args)
		exit(ft_errors(NULL, NULL, MALLOC_ERROR));
	args[0] = cmd_new;
	args[1] = ft_strdup(cmd->args_herdoc);
	args[2] = 0;
	return (args);
}

static char	**cmd_args(t_shell *cmd, t_data *data)
{
	char	*cmd_new;
	int		i;

	i = 0;
	if (cmd == NULL)
		return (NULL);
	cmd_new = get_cmd(cmd->cmd, data);
	if (!cmd_new)
		return (NULL);
	if (cmd->boolen_herdoc)
		return (herdoc_is_here(cmd, cmd_new));
	else if (!cmd->args)
		return (no_args(cmd_new));
	else
		return (normal_args(cmd, cmd_new));
	return (NULL);
}

void	execute_cmd(t_shell *cmd, t_data *data)
{
	char	**new_args;

	if (!check_in_our_cmd(cmd))
		exit(0);
	else
	{
		if (!cmd->cmd)
			exit(0);
		new_args = cmd_args(cmd, data);
		if (new_args == NULL || new_args[0] == NULL)
			exit(ft_errors("Minishell. ", cmd->cmd, CMD_NOT_FOUND));
		if (execve(new_args[0], new_args, data->env_copy) == -1)
			exit(ft_errors("Minishell. ", cmd->cmd, CMD_NOT_FOUND));
	}
}
