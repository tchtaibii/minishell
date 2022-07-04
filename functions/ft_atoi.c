/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:00:07 by ybouali           #+#    #+#             */
/*   Updated: 2022/03/27 21:14:24 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_atoi(const char *str)
{
	unsigned long	r;
	int				i;
	int				o;

	i = 0;
	r = 0;
	o = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			o = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (o * r);
}

long long	ft_atoi2(const char *str)
{
	unsigned long long		r;
	long long				o;
	int						i;

	i = 0;
	r = 0;
	o = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			o = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		r = r * 10 + (str[i++] - '0');
	if (r > LLONG_MAX || (r > LLONG_MAX && o == -1))
	{
		printf("exit\nMiniSHELL exit: %s: numeric argument required\n", str);
		exit(255);
	}
	return (o * (long long)r);
}

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index] != (char)c && s[index])
		index++;
	if (s[index] == (char)c)
		return ((char *)s + index);
	return (0);
}
