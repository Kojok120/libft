/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:06:46 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/18 20:22:38 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*p1;
	unsigned char		*p2;
	unsigned char		tmp[n];
	size_t				i;

	p1 = src;
	p2 = dest;
	i = 0;
	while (i < n)
	{
		tmp[i] = p1[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		p2[i] = tmp[i];
		i++;
	}
	return (dest);
}
