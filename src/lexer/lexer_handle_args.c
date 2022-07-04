/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_handle_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:21:20 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/27 20:22:12 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*lexer_between_sengle(t_lexer *lexer, char *value)
{
	char	*tmp;

	tmp = ft_strdup(value);
	free(value);
	lexer_advance(lexer);
	while (lexer->c != '\0' && lexer->c != 39)
		tmp = lexer_stock(lexer, tmp);
	lexer_advance(lexer);
	return (tmp);
}

static char	*double_help(t_lexer *lexer, char *value, char *tmp)
{
	while (lexer->c != '\0')
	{
		if (
			lexer->c == 36 && lexer->contents[lexer->index + 1] != '\0')
		{
			value = lexer_collect_dolar(lexer, tmp);
			tmp = value;
		}
		else
		{
			if (lexer->c == 34)
			{
				value = tmp;
				lexer_advance(lexer);
				return (value);
			}
			else
				tmp = lexer_stock(lexer, tmp);
		}
	}
	return (NULL);
}

char	*lexer_between_double(t_lexer *lexer, char *value)
{
	char	*tmp;

	tmp = ft_strdup(value);
	free(value);
	lexer_advance(lexer);
	return (double_help(lexer, value, tmp));
}

t_token	*lexer_collect_args(t_lexer *lexer)
{
	char	*value;

	value = ft_calloc(1, sizeof(char));
	while (lexer->c != '\0' && !(lexer->c == '>' || lexer->c == '<'))
	{
		if (lexer->c == 34)
			value = lexer_between_double(lexer, value);
		else if (lexer->c == 39)
			value = lexer_between_sengle(lexer, value);
		else if (
			lexer->c == 36 && lexer->contents[lexer->index + 1] != '\0')
		{
			value = lexer_collect_dolar(lexer, value);
		}
		else
			value = lexer_stock(lexer, value);
	}
	return (init_token(TOKEN_ARGS, value));
}
