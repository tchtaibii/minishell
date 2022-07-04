/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_handle_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:22:28 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/27 20:30:08 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	true(t_lexer *lexer)
{
	if (lexer->c != '\0')
	{
		if (!((lexer->c >= 9 && lexer->c <= 13) || lexer->c == ' '))
		{
			if (!(lexer->c == '>' || lexer->c == '<'))
				return (1);
		}
	}
	return (0);
}

t_token	*lexer_collect_id(t_lexer *lexer)
{
	char	*value;

	value = ft_calloc(1, sizeof(char));
	while (true(lexer))
	{
		if (lexer->c == 34)
			value = lexer_between_double(lexer, value);
		else if (lexer->c == 39)
			value = lexer_between_sengle(lexer, value);
		else if (
			lexer->c == 36 && lexer->contents[lexer->index + 1] != '\0')
			value = lexer_collect_dolar(lexer, value);
		else
			value = lexer_stock(lexer, value);
	}
	lexer->id_cmd = 1;
	return (init_token(TOKEN_CMD, value));
}
