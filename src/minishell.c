/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   minishell.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ybouali <ybouali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/02/25 19:58:41 by ybouali		   #+#	#+#			 */
/*   Updated: 2022/03/26 21:06:22 by ybouali		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	start(void)
{
	struct sigaction	sig_quit;

	sig_quit.sa_handler = SIG_IGN;
	sig_quit.sa_flags = SA_RESTART;
	g_data.sig_int.sa_flags = SA_RESTART;
	if (sigaction(SIGQUIT, &sig_quit, NULL) == -1)
	{
		ft_errors(NULL, NULL, ERROR_SEGNEL);
		return ;
	}
	ft_get_line_and_stock_data();
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	g_data.r_error = 0;
	g_data.env_copy = strdup_table(env);
	if (!g_data.env_copy)
		return (ft_errors(NULL, NULL, MALLOC_ERROR));
	g_data.n_of_cmd = 0;
	g_data.n_of_cmd_old = 0;
	start();
	ft_free_2d_table(g_data.env_copy);
	return (0);
}
