/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:38:57 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/27 20:46:37 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_lexer	*init_lexer(char *contents)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(t_lexer));
	lexer->index = 0;
	lexer->id_cmd = 0;
	lexer->id_option = 0;
	lexer->contents = contents;
	lexer->c = contents[lexer->index];
	return (lexer);
}

static t_token	*lexer_redir(t_lexer *lexer, char c)
{
	lexer_advance(lexer);
	if (lexer->contents[lexer->index] == c)
	{
		lexer_advance(lexer);
		if (c == '<')
			return (lexer_collect_redir(lexer, TOKEN_LDREDI));
		return (lexer_collect_redir(lexer, TOKEN_RDREDI));
	}
	if (c == '<')
		return (lexer_collect_redir(lexer, TOKEN_LREDI));
	return (lexer_collect_redir(lexer, TOKEN_RREDI));
}

t_token	*lexer_get_next_token(t_lexer *lexer)
{
	lexer_skep_whitespace(lexer);
	while (lexer->c != '\0' && lexer->index < ft_strlen(lexer->contents))
	{
		if ((lexer->c >= 9 && lexer->c <= 13) || lexer->c == ' ')
			lexer_skep_whitespace(lexer);
		if (lexer->c == '<')
			return (lexer_redir(lexer, '<'));
		if (lexer->c == '>')
			return (lexer_redir(lexer, '>'));
		if (lexer->id_cmd == 0)
			return (lexer_collect_id(lexer));
		if (ft_strncmp(&lexer->contents[\
		lexer_count_whitespace(lexer->contents)], "echo", 4) == 0 && \
		lexer->c == '-' && \
		lexer->id_option == 0 && \
		lexer->contents[lexer->index + 1] == 'n' && \
		(lexer->contents[lexer->index + 2] == ' ' || \
		lexer->contents[lexer->index + 2] == 'n'))
			return (lexer_collect_echo(lexer));
		return (lexer_collect_args(lexer));
	}
	return ((void *)0);
}

char	*lexer_stock(t_lexer *lexer, char *value)
{
	char	*tmp;
	char	*c;

	c = malloc(2);
	if (!c)
		return (NULL);
	c[0] = lexer->c;
	c[1] = '\0';
	tmp = ft_strjoin(value, c);
	free(value);
	free(c);
	value = tmp;
	lexer_advance(lexer);
	return (value);
}
