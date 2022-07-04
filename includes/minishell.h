/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   minishell.h										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ybouali <ybouali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/02/25 19:53:27 by ybouali		   #+#	#+#			 */
/*   Updated: 2022/03/27 12:49:57 by ybouali		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>

/* type error */

# define MALLOC_ERROR 70
# define FD_ERROR 71
# define ERROR_APP 72
# define ERROR_SEGNEL 73
# define CMD_NOT_FOUND 74
# define ERROR_EXECVE 75
# define ERROR_LINECMD 76

# define TOKEN_CMD 1
# define TOKEN_OPTION 2
# define TOKEN_ARGS 3
# define TOKEN_LREDI 4
# define TOKEN_RREDI 5
# define TOKEN_LDREDI 6
# define TOKEN_RDREDI 7

typedef struct s_data	t_data;
t_data					g_data;

typedef struct s_token
{
	int				type;
	char			*value;
	struct s_token	*next;
}	t_token;

typedef struct s_parser
{
	t_token			*token;
	struct s_parser	*next;
}	t_parser;

typedef struct s_lexer
{
	char			c;
	unsigned int	index;
	int				id_cmd;
	int				id_option;
	char			*contents;
}	t_lexer;

# define START 2020
# define NEXT 2021
# define END 2023

typedef struct s_shell
{
	int				in_file;
	int				out_file;
	int				cmd_index;
	char			*cmd;
	int				option;
	int				boolen_herdoc;
	char			*args_herdoc;
	pid_t			pid;
	char			*args;
	int				type;
	struct s_shell	*next;
}	t_shell;

typedef struct s_data
{
	struct sigaction	sig_int;
	int					r_error;
	char				**env_copy;
	int					**pip;
	int					n_of_cmd;
	int					n_of_cmd_old;
	t_parser			*cmds_parser;
	t_shell				*shell;
}	t_data;

// void		display_cmds(t_shell **head);
int			ft_handle_export_err(char **vars, int boolean);
int			echo(t_shell *cmd);
int			env(void);
void		start_executing(void);
void		execute_cmd(t_shell *cmds, t_data *data);
int			check_in_our_cmd(t_shell *cmd);
int			parser_handle_rredi(t_shell *cmds, t_token *t);
int			parser_handle_rdredi(t_shell *cmds, t_token *t);
int			fork_for_cmd(t_shell *cmd);
void		close_fds_main(void);
void		display_table(char **table);
void		show_data_and_free(void);
void		parser_handle_dherdoc(t_token *token, t_shell *cmd);
int			parser_handle_herdoc(t_shell *cmds, t_token *t);
void		convert_tokens(t_parser **cmd);
char		**no_args(char *cmd_new);
void		handler2(int sig);
void		handler(int sig);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
int			ft_isalnum(int c);
char		**ft_split(char *str, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(char *s1);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_itoa(int n);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);

/* src / parser */
t_shell		*init_shell(void);
void		push_back_shell(t_shell **list, t_shell *new);

/* src / lexer */

t_lexer		*init_lexer(char *contents);
void		lexer_advance(t_lexer *lexer);
void		lexer_back_advance(t_lexer *lexer);
void		lexer_skep_whitespace(t_lexer *lexer);
void		lexer_skep_back_whitespace(t_lexer *lexer);
t_token		*lexer_get_next_token(t_lexer *lexer);
t_token		*lexer_collect_args(t_lexer *lexer);
t_token		*lexer_collect_redir(t_lexer *lexer, int type);
t_token		*lexer_collect_id(t_lexer *lexer);
t_token		*lexer_collect_echo(t_lexer *lexer);
int			lexer_count_whitespace(char *str);
char		*lexer_collect_dolar(t_lexer *lexer, char *value);
char		*lexer_between_sengle(t_lexer *lexer, char *value);
char		*lexer_between_double(t_lexer *lexer, char *value);
char		*lexer_stock(t_lexer *lexer, char *value);
t_token		*init_token(int type, char *value);
void		push_back_token(t_token **list, t_token *new);

void		ft_free_cmds_list(t_shell **list);
void		display_tokens(t_parser **head);
int			ft_handle_err(char *line);
size_t		len_of_withespace(char *line);
void		ft_free_2d_table(char **table);
void		ft_free_parser_list(t_parser **list);

char		*find_var(char **en, char *var);
char		*ft_get_cmd(char **env, char *cmd);
int			ft_len(char *str, int c);
char		*ft_strdup_new(char *s1);
int			ft_check_nember_of_n(char *str);
char		**ft_pipe_split(char *str, char c);
int			ft_len_of_table_2(char **table);
int			ft_len_back_with_char_limit(char *str, int c);
void		push_back_parser(t_parser **list, t_parser *new);

char		**strdup_table(char **env);
void		ft_get_line_and_stock_data(void);
int			ft_strlen_with(char *s, char c);
void		rl_replace_line(const char *text, int clear_undo);
char		**ft_cnofw(char *str, int *h, char c);
char		**ft_ccofw(char *str, char c, int *f, char **table);
int			table_len(char **str);
int			ft_atoi(const char *str);
t_parser	*init_parser(void);
long long	ft_atoi2(const char *str);
int			ft_echo(t_shell *cmd);
int			ft_env(void);
int			ft_export(t_shell *cmd, char **tmp, char **args);
int			ft_unset(t_shell *cmd);
int			ft_exit(t_shell *cmd);
int			pwd(void);
int			cd(t_shell *cmd);
char		**ft_unset2(int i, int j);
int			ft_str_digit(char *str);
int			ft_errors(char *error1, char *error2, int type);
void		cd2(t_shell *cmd);
int			help_handle_pipe(char *line, int i);
int			handle_pipe(char *line);
int			handle_left(char *line, int i);
int			handle_right(char *line, int i);
int			ft_handle_redir_error(char *line);
int			ft_count_withespace(char *line);
int			line_without(char *line, int booleen, int skep);
int			help_check_for_err(char *line, int len, int boolean);
int			ft_handle_err(char *line);
char		*ft_dup_line_for_pipe(char *line);
int			skep_whitespace(char *src);
void		ft_unset3(char *args);
void		t_export_print(void);
#endif