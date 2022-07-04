/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:09:06 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/27 21:11:28 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	close_fds(t_shell *cmd)
{
	int	i;

	i = -1;
	while (++i < (g_data.n_of_cmd - 1))
	{
		if (cmd->cmd_index != i)
			close(g_data.pip[i][1]);
		if (cmd->cmd_index - 1 != i)
			close(g_data.pip[i][0]);
	}
}

void	close_fds_main(void)
{
	int	i;

	i = -1;
	while (++i < (g_data.n_of_cmd - 1))
	{
		close(g_data.pip[i][1]);
		close(g_data.pip[i][0]);
	}
}

static int	in_file(t_shell *cmd)
{
	if (cmd->in_file > 0)
		return (cmd->in_file);
	else if (cmd->cmd_index != 0)
		return (g_data.pip[cmd->cmd_index - 1][0]);
	return (0);
}

static int	out_file(t_shell *cmd)
{
	if (cmd->out_file > 0)
		return (cmd->out_file);
	else if (cmd->type != END)
		return (g_data.pip[cmd->cmd_index][1]);
	return (1);
}

int	fork_for_cmd(t_shell *cmd)
{
	cmd->pid = fork();
	if (cmd->pid == -1)
	{
		printf("ERROR FORK\n");
		g_data.r_error = 127;
		return (1);
	}
	if (cmd->pid == 0)
	{
		close_fds(cmd);
		dup2(in_file(cmd), 0);
		dup2(out_file(cmd), 1);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execute_cmd(cmd, &g_data);
	}
	return (0);
}
