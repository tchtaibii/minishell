/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   util.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ybouali <ybouali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/02/27 13:47:13 by ybouali		   #+#	#+#			 */
/*   Updated: 2022/03/27 13:46:12 by ybouali		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_2d_table(char **table)
{
	int	i;

	if (table != NULL)
	{
		i = -1;
		while (table[++i])
			free(table[i]);
		free(table);
	}
}

static void	help_free(t_token *token_head)
{
	t_token	*tmp_token;

	while (token_head)
	{
		tmp_token = token_head;
		token_head = token_head->next;
		tmp_token->next = NULL;
		free(tmp_token->value);
		free(tmp_token);
		tmp_token = NULL;
	}
	token_head = NULL;
}

void	ft_free_parser_list(t_parser **list)
{
	t_parser	*head;
	t_parser	*head_tmp;

	head = *list;
	if (head)
	{
		while (head)
		{
			help_free(head->token);
			head_tmp = head;
			head = head->next;
			head_tmp->next = NULL;
			free(head_tmp);
		}
		free(head);
		*list = NULL;
	}
}

int	ft_strlen_with(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (i);
	return (i);
}

char	*find_var(char **en, char *var)
{
	char	*test_with;
	int		i;

	i = -1;
	test_with = NULL;
	while (en[++i])
	{
		test_with = ft_substr(en[i], 0, ft_strlen_with(en[i], '='));
		if (ft_strlen_with(var, '\0') == ft_strlen_with(test_with, '\0'))
		{
			if (ft_strncmp(var, test_with, ft_strlen_with(var, '\0')) == 0)
			{
				free(test_with);
				return (en[i] + (ft_strlen_with(var, '\0') + 1));
			}
		}
		free(test_with);
	}
	return (NULL);
}
