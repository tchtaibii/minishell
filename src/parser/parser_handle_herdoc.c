/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handle_herdoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:48:50 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/27 20:52:16 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	stock_line_in(t_shell *cmd, t_token *token, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_TRUNC | O_CREAT | O_RDWR, 0666);
	if (fd < 0)
	{
		free(cmd->args_herdoc);
		return ;
	}
	while (42)
	{
		line = readline("::$> ");
		if (line == NULL \
		|| (ft_strncmp(token->value, line, ft_strlen(line)) == 0))
		{
			close(fd);
			exit(0);
		}
		else
			ft_putendl_fd(line, fd);
	}
}

static char	*name_file_n(void)
{
	char	*name_file;
	char	*number_of_file;

	number_of_file = ft_itoa(g_data.n_of_cmd);
	if (!number_of_file)
		return (NULL);
	name_file = ft_strjoin("/tmp/.env_", number_of_file);
	free(number_of_file);
	if (!name_file)
		return (NULL);
	return (name_file);
}

void	parser_handle_dherdoc(t_token *token, t_shell *cmd)
{
	int		pid;
	char	*name_file;

	if (cmd->boolen_herdoc)
		free(cmd->args_herdoc);
	name_file = name_file_n();
	if (!name_file)
		return ;
	cmd->args_herdoc = name_file;
	cmd->boolen_herdoc = 1;
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		stock_line_in(cmd, token, name_file);
	}
	else
		waitpid(pid, 0, 0);
}

int	parser_handle_herdoc(t_shell *cmds, t_token *t)
{
	if (cmds->in_file > 0)
		close(cmds->in_file);
	cmds->in_file = open(t->value, O_RDONLY, 0644);
	if (cmds->in_file < 0)
	{
		printf("ERROR FD\n");
		ft_free_parser_list(&g_data.cmds_parser);
		ft_free_cmds_list(&g_data.shell);
		g_data.r_error = 127;
		exit(1);
	}
	return (1);
}
