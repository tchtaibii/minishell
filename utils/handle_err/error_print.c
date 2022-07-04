/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   error_print.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ybouali <ybouali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/25 12:07:17 by ybouali		   #+#	#+#			 */
/*   Updated: 2022/03/27 12:19:21 by ybouali		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_string(int type)
{
	if (type == MALLOC_ERROR)
		return ("malloc faild");
	if (type == FD_ERROR)
		return ("somthing is wrong with fd");
	if (type == ERROR_APP)
		return ("somthing is wrong !!");
	if (type == ERROR_SEGNEL)
		return ("error signal !!");
	if (type == CMD_NOT_FOUND)
		return (" : command not found");
	if (type == ERROR_EXECVE)
		return (" execve faild");
	return ("");
}

int	ft_errors(char *error1, char *error2, int type)
{
	if (error1)
		ft_putstr_fd(error1, 2);
	if (error2)
		ft_putstr_fd(error2, 2);
	ft_putendl_fd(get_string(type), 2);
	return (127);
}
