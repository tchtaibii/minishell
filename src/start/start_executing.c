/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_executing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:00:58 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/27 21:09:54 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pipes(void)
{
	int	i;

	i = -1;
	while (++i < (g_data.n_of_cmd - 1))
	{
		if (pipe(g_data.pip[i]) == -1)
			return (-1);
	}
	return (0);
}

static void	free_table2d_int(void)
{
	int	i;

	i = -1;
	if (g_data.n_of_cmd_old != 0)
	{
		while (++i < (g_data.n_of_cmd_old - 1))
			free(g_data.pip[i]);
		free(g_data.pip);
	}
	g_data.n_of_cmd_old = 0;
}

void	init_table(void)
{
	int	i;

	i = -1;
	free_table2d_int();
	g_data.pip = malloc(sizeof(int *) * (g_data.n_of_cmd - 1));
	while (++i < (g_data.n_of_cmd - 1))
		g_data.pip[i] = malloc(sizeof(int) * 2);
}

void	wait_pids(t_shell **cmds)
{
	t_shell		*wai_cmd;
	int			r_return;

	wai_cmd = *cmds;
	close_fds_main();
	while (wai_cmd)
	{
		if (wai_cmd->in_file > 0)
			close(wai_cmd->in_file);
		else if (wai_cmd->out_file > 0)
			close(wai_cmd->out_file);
		waitpid(wai_cmd->pid, &r_return, 0);
		if (WIFSIGNALED(r_return))
			g_data.r_error = 130;
		else
			g_data.r_error = WEXITSTATUS(r_return);
		wai_cmd = wai_cmd->next;
	}
}

void	start_executing(void)
{
	t_shell		*hcmd;

	hcmd = g_data.shell;
	if (g_data.n_of_cmd == 1 && hcmd->out_file == 0 && !check_in_our_cmd(hcmd))
		return ;
	else
	{
		init_table();
		if (pipes() == -1)
			return ;
		while (hcmd)
		{
			fork_for_cmd(hcmd);
			hcmd = hcmd->next;
		}
		wait_pids(&g_data.shell);
	}
}
