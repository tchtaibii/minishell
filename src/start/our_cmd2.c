/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   our_cmd2.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ybouali <ybouali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/25 22:00:26 by tchtaibi		  #+#	#+#			 */
/*   Updated: 2022/03/27 16:04:29 by ybouali		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_unset2(int i, int j)
{
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * table_len(g_data.env_copy));
	while (i > ++j)
		tmp[j] = ft_strdup(g_data.env_copy[j]);
	while (g_data.env_copy[j + 1])
	{
		tmp[j] = ft_strdup(g_data.env_copy[j + 1]);
		j++;
	}
	tmp[j] = 0;
	return (tmp);
}

void	ft_exit_last_if(char *str)
{
	ft_atoi2(str);
	printf("exit\n");
	exit(ft_atoi2(str));
}

int	ft_exit(t_shell *cmd)
{
	char	**args;

	if (!cmd->args)
	{
		printf("exit\n");
		exit(0);
	}
	else
		args = ft_split(cmd->args, ' ');
	if (!ft_str_digit(args[0]))
	{
		printf("exit\nMiniSHELL exit: %s: numeric argument required\n", args[0]);
		exit(255);
	}
	else if (ft_str_digit(args[0]) && table_len(args) > 1)
	{
		printf("exit\nMiniSHELL exit: too many arguments\n");
		g_data.r_error = 1;
	}
	else if (ft_str_digit(args[0]) && table_len(args) == 1)
		ft_exit_last_if(args[0]);
	return (0);
}

int	pwd(void)
{
	char	s[PATH_MAX];

	if (getcwd(s, sizeof(s)) != NULL)
	{
		printf("%s\n", s);
		return (0);
	}
	else
	{
		perror("getcwd() error");
		g_data.r_error = 1;
		return (0);
	}
	return (1);
}

int	cd(t_shell *cmd)
{
	char	*home;

	home = find_var(g_data.env_copy, "HOME");
	if (!cmd->args)
	{
		if (!home)
		{
			ft_putendl_fd("Minishell: cd: HOME not set", 2);
			g_data.r_error = 1;
			return (0);
		}
		chdir(home);
		return (0);
	}
	else if (cmd->args)
		cd2(cmd);
	return (1);
}
