/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:13:28 by aaaraba           #+#    #+#             */
/*   Updated: 2024/04/30 17:13:50 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_overf(unsigned long r, int s)
{
	int	n;

	n = 0;
	if (r > 9223372036854775807)
	{
		if (s % 2 == 0)
			n = -1;
		else
			n = 0;
	}
	return (n);
}

long	ft_atoi(const char *str)
{
	int				i;
	int				s;
	unsigned long	r;

	i = 0;
	s = 0;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + str[i] - '0';
		str++;
		if (r > 9223372036854775807)
			return (ft_overf(r, s));
	}
	if (s % 2 == 0)
		return ((long)r);
	return ((long)-r);
}
