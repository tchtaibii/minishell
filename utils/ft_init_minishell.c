/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_init_minishell.c								:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ybouali <ybouali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/05 21:48:20 by ybouali		   #+#	#+#			 */
/*   Updated: 2022/03/21 14:58:32 by ybouali		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/minishell.h"

t_parser	*init_parser(void)
{
	t_parser	*node;

	node = (t_parser *)malloc(sizeof(t_parser));
	if (!node)
		return (NULL);
	node->token = NULL;
	node->next = NULL;
	return (node);
}

t_shell	*init_shell(void)
{
	t_shell	*node;

	node = (t_shell *)malloc(sizeof(t_shell));
	if (!node)
		return (NULL);
	node->in_file = 0;
	node->out_file = 0;
	node->option = 0;
	node->boolen_herdoc = 0;
	node->cmd = NULL;
	node->args_herdoc = NULL;
	node->type = START;
	node->args = NULL;
	node->next = NULL;
	return (node);
}

void	push_back_shell(t_shell **list, t_shell *new)
{
	t_shell	*head;

	head = *list;
	if (*list == NULL)
		*list = new;
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = new;
	}
}

void	push_back_parser(t_parser **list, t_parser *new)
{
	t_parser	*head;

	head = *list;
	if (*list == NULL)
		*list = new;
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = new;
	}
}
