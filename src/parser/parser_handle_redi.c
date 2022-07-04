/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handle_redi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:52:29 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/27 20:53:06 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parser_handle_rredi(t_shell *cmds, t_token *t)
{
	if (cmds->out_file > 0)
		close(cmds->out_file);
	cmds->out_file = open(t->value, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (cmds->out_file < 0)
	{
		printf("ERROR FD\n");
		ft_free_parser_list(&g_data.cmds_parser);
		ft_free_cmds_list(&g_data.shell);
		g_data.r_error = 127;
		exit(1);
	}
	return (1);
}

int	parser_handle_rdredi(t_shell *cmds, t_token *t)
{
	if (cmds->out_file > 0)
		close(cmds->out_file);
	cmds->out_file = open(t->value, O_CREAT | O_RDWR | O_APPEND, 0666);
	if (cmds->out_file < 0)
	{
		printf("ERROR FD\n");
		ft_free_parser_list(&g_data.cmds_parser);
		ft_free_cmds_list(&g_data.shell);
		g_data.r_error = 127;
		exit(1);
	}
	return (1);
}
