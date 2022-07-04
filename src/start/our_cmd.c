/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   our_cmd.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ybouali <ybouali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/25 21:57:40 by tchtaibi		  #+#	#+#			 */
/*   Updated: 2022/03/27 13:31:51 by ybouali		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_export_2(char **args, int i, int j)
{
	int		k;
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * (i + j + 1));
	k = -1;
	while (++k < i)
		tmp[k] = ft_strdup(g_data.env_copy[k]);
	i = -1;
	while (++i < j)
		tmp[k++] = ft_strdup(args[i]);
	tmp[k] = 0;
	return (tmp);
}

int	ft_export(t_shell *cmd, char **tmp, char **args)
{
	int		k;
	int		stop;

	k = -1;
	stop = 0;
	if (cmd->args == NULL)
		t_export_print();
	else
	{
		args = ft_split(cmd->args, ' ');
		ft_unset(cmd);
		tmp = ft_export_2(args, table_len(g_data.env_copy), table_len(args));
		ft_free_2d_table(g_data.env_copy);
		ft_free_2d_table(args);
		g_data.env_copy = strdup_table(tmp);
		ft_free_2d_table(tmp);
	}
	g_data.r_error = 0;
	return (g_data.r_error);
}

void	help_unset3(int k, char **tmp_1, char **tmp_2)
{
	char	**tmp;

	tmp = ft_unset2(k, -1);
	ft_free_2d_table(g_data.env_copy);
	g_data.env_copy = strdup_table(tmp);
	ft_free_2d_table(tmp);
	free (*tmp_1);
	free (*tmp_2);
}

void	ft_unset3(char *args)
{
	char	*tmp_1;
	char	*tmp_2;
	int		k;

	k = -1;
	while (g_data.env_copy[++k])
	{
		tmp_1 = ft_substr(g_data.env_copy[k], 0, \
			ft_strlen_with(g_data.env_copy[k], '='));
		tmp_2 = ft_substr(args, 0, \
			ft_strlen_with(args, '='));
		if (ft_strlen(tmp_1) == ft_strlen(tmp_2))
		{
			if (ft_strncmp(tmp_1, tmp_2, ft_strlen(tmp_2)) == 0)
			{
				help_unset3(k, &tmp_1, &tmp_2);
				return ;
			}
			free (tmp_1);
			free (tmp_2);
		}
	}
}

int	ft_unset(t_shell *cmd)
{
	char	**args;
	int		i;

	if (cmd->args)
	{
		args = ft_split(cmd->args, ' ');
		i = -1;
		while (args[++i])
			ft_unset3(args[i]);
		ft_free_2d_table(args);
	}
	g_data.r_error = 0;
	return (g_data.r_error);
}
