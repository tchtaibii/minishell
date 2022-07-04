/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   tools_1.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ybouali <ybouali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/21 13:37:41 by ybouali		   #+#	#+#			 */
/*   Updated: 2022/03/27 12:08:11 by ybouali		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_in_our_cmd(t_shell *cmd)
{
	if (cmd->cmd != NULL)
	{
		if (cmd->cmd[0] == '\0')
			return (1);
		else if (!ft_strncmp(cmd->cmd, "echo", ft_strlen(cmd->cmd)) \
			|| !ft_strncmp(cmd->cmd, "ECHO", ft_strlen(cmd->cmd)))
			return (echo(cmd));
		else if (!ft_strncmp(cmd->cmd, "env", ft_strlen(cmd->cmd)) \
			|| !ft_strncmp(cmd->cmd, "ENV", ft_strlen(cmd->cmd)))
			return (env());
		else if (!ft_strncmp(cmd->cmd, "export", ft_strlen(cmd->cmd)))
			return (ft_export(cmd, NULL, NULL));
		else if (!ft_strncmp(cmd->cmd, "unset", ft_strlen(cmd->cmd)))
			return (ft_unset(cmd));
		else if (!ft_strncmp(cmd->cmd, "cd", ft_strlen(cmd->cmd)) \
			|| !ft_strncmp(cmd->cmd, "CD", ft_strlen(cmd->cmd)))
			return (cd(cmd));
		else if (!ft_strncmp(cmd->cmd, "exit", ft_strlen(cmd->cmd)))
			return (ft_exit(cmd));
		else if (!ft_strncmp(cmd->cmd, "pwd", ft_strlen(cmd->cmd)) \
			|| !ft_strncmp(cmd->cmd, "PWD", ft_strlen(cmd->cmd)))
			return (pwd());
	}
	return (1);
}

int	table_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**no_args(char *cmd_new)
{
	char	**args;

	args = (char **)malloc(sizeof(char *) * 2);
	if (!args)
		exit(ft_errors(NULL, NULL, MALLOC_ERROR));
	args[0] = cmd_new;
	args[1] = 0;
	return (args);
}
