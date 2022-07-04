/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:08:43 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/27 20:09:23 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_stock_join(char *str_1, char *str_2, char **str_new)
{
	int		index_1;
	int		index_2;

	index_1 = 0;
	while (str_1[index_1])
	{
		str_new[0][index_1] = str_1[index_1];
		index_1++;
	}
	index_2 = 0;
	while (str_2[index_2])
	{
		str_new[0][index_1] = str_2[index_2];
		index_1++;
		index_2++;
	}
	str_new[0][index_1] = '\0';
	return (str_new[0]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (void *)0;
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	str = (char *)ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	if (!str)
		return (NULL);
	return (ft_stock_join(s1, s2, &str));
}

char	*ft_strdup(char *s1)
{
	char	*buff;
	int		len;

	if (!s1)
		return (ft_strdup(""));
	buff = (void *)0;
	len = ft_strlen(s1);
	buff = (char *)ft_calloc(len + 1, sizeof(char));
	if (!buff)
		return (buff);
	ft_strlcpy(buff, s1, len + 1);
	return (buff);
}
