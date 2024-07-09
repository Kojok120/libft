/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:21:12 by kokamoto          #+#    #+#             */
/*   Updated: 2024/05/08 21:24:07 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*array;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	array = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (array == NULL)
		return (NULL);
	ft_strlcpy(array, s1, ft_strlen(s1)+ 1);
	ft_strlcpy(array + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (array);
}

// int main (void)
// {
// 	printf("%s\n", ft_strjoin(NULL, NULL));
// 	printf("%s\n", ft_strjoin("a", NULL));
// 	printf("%s\n", ft_strjoin(NULL, "a"));
// 	printf("%s\n", ft_strjoin("a", "a"));
// }
