/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:38:44 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/20 15:56:40 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strijdup(char const *src, size_t i, size_t j)
{
    size_t k;
    size_t l;
	size_t		len;
	char	*array;

	len = ft_strlen(src);
	array = (char *)malloc((len + 1) * sizeof(char));
	if (array == NULL)
		return (NULL);
	k = 0;
    l = i;
	while (src[k] && k < ft_strlen(src) - j - l)
	{
		array[k] = src[i];
        k++;
		i++;
	}
	array[k] = '\0';
	return (array);
}


size_t  ft_floc(char const *s1, char const *set)
{
    size_t i;
    size_t k;
    size_t check;

    i = 0;
    while (s1[i])
    {
        check = 0;
        k = 0;
        while (set[k])
        {
            if (s1[i] != set[k])
                check += 1;
            k++;
        }
        if (check == ft_strlen(set))
            return (i);
        i++;
    }
    return (i);
}
size_t ft_lloc(char const *s1, char const *set)
{
    size_t j;
    size_t k;
    size_t check;

    j = 0;
    while (s1[j])
    {
        check = 0;
        k = 0;
        while (set[k])
        {
            if (s1[ft_strlen(s1) - 1 - j] != set[k])
                check += 1;
            k++;
        }
        if (check == ft_strlen(set))
            return (j);
        j++;
    }
    return (j);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    return (ft_strijdup(s1, ft_floc(s1, set), ft_lloc(s1, set)));
}
