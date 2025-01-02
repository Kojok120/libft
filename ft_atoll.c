/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:10:51 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/02 13:11:04 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign * num > LLONG_MAX / 10 || (sign * num * 10 > LLONG_MAX
				- (str[i] - '0')))
			return ((long long)LLONG_MAX);
		if (sign * num < LLONG_MIN / 10 || (sign * num * 10 < LLONG_MIN
				+ (str[i] - '0')))
			return ((long long)LLONG_MIN);
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (sign * num);
}
