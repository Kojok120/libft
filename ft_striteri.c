/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:10:59 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/21 21:13:40 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void    ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    int i;

    i = 0;
    while (s[i])
    {
        f(i, &s[i]);
        i++;
    }
    // return (s);
}
