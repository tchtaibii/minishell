/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:54:54 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/27 20:55:11 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	help_convert_token(t_token *t, t_shell *cmds)
{
	while (t)
	{
		if (t->type == TOKEN_CMD)
			cmds->cmd = ft_strdup(t->value);
		else if (t->type == TOKEN_RREDI)
			parser_handle_rredi(cmds, t);
		else if (t->type == TOKEN_RDREDI)
			parser_handle_rdredi(cmds, t);
		else if (t->type == TOKEN_LREDI)
			parser_handle_herdoc(cmds, t);
		else if (t->type == TOKEN_LDREDI)
			parser_handle_dherdoc(t, cmds);
		else if (t->type == TOKEN_ARGS)
			cmds->args = ft_strdup(t->value);
		else if (t->type == TOKEN_OPTION)
			cmds->option = 1;
		t = t->next;
	}
	if (cmds->cmd_index != 0)
		cmds->type = NEXT;
}

void	convert_tokens(t_parser **cmd)
{
	t_parser	*h;
	t_shell		*cmds;

	h = *cmd;
	g_data.n_of_cmd = 0;
	while (h)
	{
		cmds = init_shell();
		cmds->cmd_index = g_data.n_of_cmd;
		push_back_shell(&g_data.shell, cmds);
		help_convert_token(h->token, cmds);
		h = h->next;
		if (h == NULL)
			cmds->type = END;
		g_data.n_of_cmd += 1;
	}
}
