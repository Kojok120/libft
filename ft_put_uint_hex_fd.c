/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint_hex_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:34:44 by kokamoto          #+#    #+#             */
/*   Updated: 2024/07/09 23:30:46 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_put_uint_hex_fd(unsigned int n, int fd, char format)
{
    char   *base;
    int    i;
    
    if (format == 'x')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    if (n < 16)
    {
        write(fd, &base[n], 1);
        return ;
    }
    else
    {
        i = n % 16;
        n = n / 16;
        ft_put_uint_hex_fd(n, fd, format);
        write(fd, &base[i], 1);
    }
}
