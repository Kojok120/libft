/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:23:58 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/21 21:55:17 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
    {
		write(fd, "-2147483648", 11);
        return ;
    }
	if (n < 0)
    {
        n *= -1;
        write(fd, "-", 1);
    }
    if (n < 10)
    {
        c = n + '0';
        write(fd, &c, 1);
        return ;
    }
    else
    {
        c = n % 10 + '0';
        n = n / 10;
        ft_putnbr_fd(n, fd);
        write(fd, &c, 1);
    }
}

