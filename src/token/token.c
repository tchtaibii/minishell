/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   token.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ybouali <ybouali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/02/25 20:05:07 by ybouali		   #+#	#+#			 */
/*   Updated: 2022/03/19 03:43:16 by ybouali		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*init_token(int type, char *value)
{
	t_token	*token;
	char	*n;

	n = "n";
	token = NULL;
	token = malloc(sizeof(t_token));
	token->type = type;
	if (type == TOKEN_OPTION)
		token->value = ft_strdup(n);
	else
		token->value = value;
	token->next = NULL;
	return (token);
}

void	push_back_token(t_token **list, t_token *new)
{
	t_token	*head;

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
