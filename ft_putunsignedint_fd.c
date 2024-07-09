/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignedint_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:30:39 by kokamoto          #+#    #+#             */
/*   Updated: 2024/07/09 16:03:18 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putunsignedint_fd(unsigned int n, int fd)
{
    char    c;

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
        ft_putunsignedint_fd(n, fd);
        write(fd, &c, 1);
    }
}
