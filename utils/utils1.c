/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils1.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ybouali <ybouali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/01 22:14:56 by ybouali		   #+#	#+#			 */
/*   Updated: 2022/03/07 21:31:40 by ybouali		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_len(char *str, int c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == (char)c)
			i++;
		str++;
	}
	return (i);
}

int	ft_len_back_with_char_limit(char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	i--;
	if (str[i] == (char)c)
		i--;
	while (str[i] && str[i] != (char)c)
		i--;
	return (i);
}

static void	ft_stock_dup(char *dst, char *src)
{
	int	index;

	index = 0;
	while (*src)
	{
		if (*src == (char)34)
			src++;
		else
		{
			dst[index] = *src;
			index++;
			src++;
		}
	}
	dst[index] = '\0';
}

char	*ft_strdup_new(char *s1)
{
	char	*buff;
	int		len;

	if (!s1)
		return (ft_strdup(""));
	buff = (void *)0;
	len = (ft_strlen(s1) - ft_len(s1, 34));
	buff = (char *)ft_calloc(len + 1, sizeof(char));
	if (!buff)
		return (buff);
	ft_stock_dup(buff, s1);
	return (buff);
}
