/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   display.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ybouali <ybouali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/18 03:25:35 by ybouali		   #+#	#+#			 */
/*   Updated: 2022/03/24 17:24:54 by ybouali		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_cmds_list(t_shell **list)
{
	t_shell	*head;
	t_shell	*head_tmp;

	head = *list;
	if (head)
	{
		while (head != NULL)
		{
			free(head->cmd);
			if (head->boolen_herdoc)
				free(head->args_herdoc);
			free(head->args);
			head_tmp = head;
			head = head->next;
			head_tmp->next = NULL;
			free(head_tmp);
		}
		free(head);
		*list = NULL;
	}
	g_data.n_of_cmd_old = g_data.n_of_cmd;
	g_data.n_of_cmd = 0;
}

void	display_tokens(t_parser **head)
{
	t_parser	*h;
	t_token		*t;

	h = *head;
	while (h)
	{
		t = h->token;
		printf("\n***********TOKENS OF CMD*********\n");
		while (t)
		{
			printf("TOKEN[%d, %s]\n", t->type, t->value);
			t = t->next;
		}
		h = h->next;
	}
}

void	display_table(char **table)
{
	int	i;

	i = -1;
	if (!*table)
	{
		while (table[++i] != 0)
			printf("%s\n", table[i]);
	}
}

// void	display_cmds(t_shell **head)
// {
// 	t_shell	*h;

// 	h = *head;
// 	while (h)
// 	{
// 		printf("\n\n***********CMD*********\n\n");
// 		printf("TYPE [%d] INDEX [%d] NUMBER OF CMDS{%d}\n",
//h->type, h->cmd_index, g_data.n_of_cmd);
// 		printf("IN FILE[%d]\nOUT FILE[%d]\n", h->in_file, 
// 			h->out_file);
// 		printf("CDM [%s]\nNORMALS ARGS[%s]\nOPTION [%d]\nBOOLEN
//HERDOC[%d], FILE HERDOC[%s]\n",
// h->cmd, h->args, h->option, h->boolen_herdoc, h->args_herdoc);
// 		h = h->next;
// 	}
// }
