/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:09:33 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/28 02:08:55 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*a;
	unsigned char	*b;

	if (!s1)
		return (404);
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	index = 0;
	while (index < n && a[index] && b[index])
	{
		if (a[index] == b[index])
			index++;
		else
			return (a[index] - b[index]);
	}
	if (index == n)
		return (0);
	return (a[index] - b[index]);
}

static void	ft_stock(char *buff, char const *str, size_t start, size_t len)
{
	size_t	index;

	index = 0;
	while (str[index] && index < len)
	{
		buff[index] = str[start];
		start++;
		index++;
	}
	buff[index] = '\0';
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*buff;
	size_t	index;

	buff = (void *)0;
	if (s == NULL)
		return (NULL);
	index = ft_strlen(s);
	if (index == 0 || start >= index)
	{
		buff = (char *)malloc(1);
		*buff = '\0';
		return (buff);
	}
	if (index < len)
		len = index;
	buff = (char *)malloc((len + 1) * sizeof(char));
	if (!buff)
		return (buff);
	ft_stock(buff, s, start, len);
	return (buff);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
