/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:56:59 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/20 11:43:06 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stddef.h>
#include <limits.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	long	num;
	long	ov_div;
	int	ov_mod;
	long	un_div;
	int	un_mod;

	i = 0;
	sign = 1;
	num = 0;
	ov_div = LONG_MAX / 10;
	ov_mod = LONG_MAX % 10;
	un_div = LONG_MIN / 10;
	un_mod = LONG_MIN % 10;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
		if (sign * num > ov_div || (sign * num == ov_div && str[i] - '0' > ov_mod))
			return ((int)LONG_MAX);
		if (sign * num < un_div || (sign * num == un_div && str[i] - '0' > un_mod))
			return ((int)LONG_MIN);
	}
	return (sign * num);
}
