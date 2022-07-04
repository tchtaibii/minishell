/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_cmd_line.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ybouali <ybouali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/02/27 13:37:26 by ybouali		   #+#	#+#			 */
/*   Updated: 2022/03/26 21:30:08 by ybouali		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	stock_cmd(char *line)
{
	t_lexer		*lexer;
	t_token		*token;
	t_parser	*new;

	if (!line)
		return (ft_errors(NULL, NULL, MALLOC_ERROR));
	new = init_parser();
	if (!new)
		return (ft_errors(NULL, NULL, MALLOC_ERROR));
	push_back_parser(&g_data.cmds_parser, new);
	lexer = init_lexer(line);
	if (!lexer)
		return (ft_errors(NULL, NULL, MALLOC_ERROR));
	while (42)
	{
		token = lexer_get_next_token(lexer);
		if (token == NULL)
			break ;
		push_back_token(&new->token, token);
	}
	free(lexer->contents);
	free(lexer);
	return (0);
}

static char	*get_line(void)
{
	char	*line;

	g_data.sig_int.sa_handler = &handler;
	if (sigaction(SIGINT, &g_data.sig_int, NULL) == -1)
	{
		ft_errors(NULL, NULL, ERROR_SEGNEL);
		exit(127);
	}
	line = readline("\033[0;31mMinishell\033[0;33m::$> \033[0;37m");
	if (line == NULL)
	{
		printf("exit\n");
		exit(0);
	}
	else if (line[0] == '\0')
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	return (line);
}

static int	help_norm_1(char *line)
{
	char	**s_pip;
	int		i;

	s_pip = ft_pipe_split(line, '|');
	if (!s_pip)
		return (ft_errors(NULL, NULL, MALLOC_ERROR));
	free(line);
	g_data.cmds_parser = NULL;
	g_data.shell = NULL;
	i = -1;
	while (s_pip[++i])
		if (stock_cmd(ft_strdup(s_pip[i])))
			return (1);
	ft_free_2d_table(s_pip);
	if (g_data.cmds_parser != NULL)
		convert_tokens(&g_data.cmds_parser);
	if (g_data.shell != NULL)
	{
		start_executing();
		ft_free_parser_list(&g_data.cmds_parser);
		ft_free_cmds_list(&g_data.shell);
	}
	return (0);
}

static int	help_norm(char *line)
{
	add_history(line);
	if (ft_handle_err(line))
	{
		free(line);
		g_data.r_error = 250;
		ft_errors(NULL, NULL, ERROR_APP);
	}
	else
	{
		if (ft_strlen(line) != len_of_withespace(line))
			if (help_norm_1(line))
				return (1);
	}
	return (0);
}

void	ft_get_line_and_stock_data(void)
{
	char	*line;

	while (1337)
	{
		line = get_line();
		g_data.sig_int.sa_handler = &handler2;
		if (sigaction(SIGINT, &g_data.sig_int, NULL) == -1)
		{
			ft_errors(NULL, NULL, ERROR_SEGNEL);
			g_data.r_error = 1;
			break ;
		}
		else if (line != NULL)
		{
			if (help_norm(line))
				break ;
		}
	}
}
