/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_handle_dolar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:30:50 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/27 20:31:40 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*question_mark(t_lexer *lexer, char *value)
{
	char	*tmp_1;
	char	*tmp;

	tmp = ft_itoa(g_data.r_error);
	tmp_1 = ft_strjoin(value, tmp);
	free(value);
	free(tmp);
	lexer_advance(lexer);
	value = tmp_1;
	return (value);
}

static char	*dolar_mark(t_lexer *lexer, char *value)
{
	char	*tmp;
	char	*tmp_1;

	tmp = ft_itoa(getpid());
	tmp_1 = ft_strjoin(value, tmp);
	free(value);
	free(tmp);
	lexer_advance(lexer);
	value = tmp_1;
	return (value);
}

static char	*var_mark(t_lexer *lexer, char *value)
{
	char	*tmp;
	char	*tmp_1;

	tmp = ft_strdup("");
	while (lexer->c != '\0' && (ft_isalnum(lexer->c) || lexer->c == '_'))
	{
		tmp_1 = ft_strjoin(tmp, &lexer->c);
		free(tmp);
		tmp = tmp_1;
		lexer_advance(lexer);
	}
	tmp_1 = find_var(g_data.env_copy, tmp);
	if (!tmp_1)
		tmp_1 = ft_strdup("");
	free(tmp);
	tmp = ft_strjoin(value, tmp_1);
	free(value);
	value = tmp;
	return (value);
}

char	*lexer_collect_dolar(t_lexer *lexer, char *value)
{
	lexer_advance(lexer);
	if (lexer->c == '?')
		value = question_mark(lexer, value);
	else if (ft_isalpha(lexer->c))
		value = var_mark(lexer, value);
	else if (lexer->c == 36)
		value = dolar_mark(lexer, value);
	else if (ft_isdigit(lexer->c))
		lexer_advance(lexer);
	return (value);
}
