/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmark <mmark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:58:30 by jvoor             #+#    #+#             */
/*   Updated: 2019/08/14 19:25:26 by mmark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long long		ft_atoi_dec(char *str)
{
	long long	i;

	i = 0;
	while ('0' <= *str && *str <= '9')
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	return (i);
}

long long		ft_atoi_hex(char *str)
{
	long long	i;

	i = 0;
	while (('0' <= *str && *str <= '9') || ('a' <= *str && *str <= 'f')
		|| ('A' <= *str && *str <= 'F'))
	{
		if ('0' <= *str && *str <= '9')
		{
			i = i * 16 + (*str - 48);
			str++;
		}
		else if ('a' <= *str && *str <= 'f')
		{
			i = i * 16 + (*str - 87);
			str++;
		}
		else if ('A' <= *str && *str <= 'F')
		{
			i = i * 16 + (*str - 55);
			str++;
		}
	}
	return (i);
}

int				ft_atoi_h(char *str)
{
	long long	i;
	int			flag;

	i = 0;
	flag = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	if (*str == '0' && *(++str) == 'x')
		i = ft_atoi_hex(++str);
	else
		i = ft_atoi_dec(str);
	if (flag == 1 && i != i * 10 / 10)
		return (-1);
	if (flag == -1 && i != i * 10 / 10)
		return (0);
	return (i * flag);
}
