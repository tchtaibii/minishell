NAME = minishell

SRCS = src/start/execute_cmds.c \
	   src/start/start_executing.c \
	   src/start/tools_1.c \
	   src/start/tools_2.c \
	   src/start/our_cmd.c \
	   src/start/our_cmd2.c \
	   src/start/our_cmd3.c \
	   functions/ft_calloc.c \
	   functions/ft_atoi.c \
	   functions/ft_isalnum.c \
	   functions/ft_strjoin.c \
	   functions/ft_split.c \
	   functions/ft_strncmp.c \
	   functions/ft_itoa.c \
	   functions/ft_putendl_fd.c \
	   src/lexer/lexer.c \
	   src/lexer/lexer_handle_args.c \
	   src/lexer/lexer_handle_cmd.c \
	   src/lexer/lexer_handle_dolar.c \
	   src/lexer/lexer_handle_echo_option.c \
	   src/lexer/lexer_handle_redir.c \
	   src/parser/parser_handle_herdoc.c \
	   src/parser/parser_handle_redi.c \
	   src/parser/parser.c \
	   src/get_start/get_cmd_line.c \
	   src/get_start/strdup_func.c \
	   src/token/token.c \
	   utils/util.c \
	   utils/handle_err/handle_err.c \
	   utils/handle_err/handle_err2.c \
	   utils/handle_err/handle_err3.c \
	   utils/handle_err/error_print.c \
	   utils/handle_err/handle_err_help.c \
	   utils/display/display.c \
	   utils/split_pipe/ft_pipe_split.c \
	   utils/split_pipe/pipe_help_split.c \
	   utils/split_pipe/help_2.c \
	   utils/util2.c \
	   utils/utils1.c \
	   utils/ft_init_minishell.c \
	   src/minishell.c \

OBJS	= 	$(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra 

RM = rm -rf

READLINEFLAGS = -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include

HEADER = ./includes/minishell.h

MAKE = make
 
all: $(NAME)

$(NAME): $(OBJS)
		@gcc ${FLAGS} $(OBJS) $(READLINEFLAGS) -o ${NAME}

.c.o: $(SRCS)
	@gcc ${FLAGS} -I $(HEADER) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
