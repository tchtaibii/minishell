/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_handle_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:37:07 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/27 20:38:33 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	lexer_advance(t_lexer *lexer)
{
	if (lexer->c != '\0' && lexer->index < ft_strlen(lexer->contents))
	{
		lexer->index += 1;
		lexer->c = lexer->contents[lexer->index];
	}
}

void	lexer_back_advance(t_lexer *lexer)
{
	if (lexer->index > 0)
	{
		lexer->index -= 1;
		lexer->c = lexer->contents[lexer->index];
	}
}

void	lexer_skep_whitespace(t_lexer *lexer)
{
	while ((lexer->c >= 9 && lexer->c <= 13) || lexer->c == ' ')
		lexer_advance(lexer);
}

int	lexer_count_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')))
		i++;
	return (i);
}

t_token	*lexer_collect_redir(t_lexer *lexer, int type)
{
	char	*value;

	value = ft_strdup("");
	lexer_skep_whitespace(lexer);
	while (lexer->c != '\0' && \
	!((lexer->c >= 9 && lexer->c <= 13) || lexer->c == ' ') && \
	!(lexer->c == '>' || lexer->c == '<'))
	{
		if (lexer->c == 34)
			value = lexer_between_double(lexer, value);
		else if (lexer->c == 39)
			value = lexer_between_sengle(lexer, value);
		else if (lexer->c == 36 && lexer->contents[lexer->index + 1] != '\0')
			value = lexer_collect_dolar(lexer, value);
		else
			value = lexer_stock(lexer, value);
	}
	return (init_token(type, value));
}
