/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:05:17 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/20 16:57:54 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdio.h>


char    *ft_reverse(char *array, long n, int i)
{
    while (n > 0)
    {
        array[i] = n % 10 + '0';
        i++;
    }
}

char    *ft_itoa(int n)
{
    int i;
    long n2;
    char    *array;

    i = 0;
    n2 = n;
    array = (char *)malloc(11);
    if (array == NULL)
        return (NULL);
    if (n2 == 0)
    {
        array[0] = '0';
        i++;
    }
    if (n2 < 0)
    {
        array[0] = '-';
        n2 = -n2;
        i++;
    }
    return (ft_reverse(array, n2, i));
}
