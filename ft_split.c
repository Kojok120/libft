/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:38:03 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/22 20:27:46 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *src, int n)
{
	int		i;
	int		len;
	char	*array;

	len = ft_strlen(src);
	array = (char *)malloc((len + 1) * sizeof(char));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		array[i] = src[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	**ft_split2(char const *s, char c, char **array, int i)
{
	int	j;
	int	n;

	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			n = 0;
			while (s[i + n] && s[i + n] != c)
				n++;
			array[j] = ft_strndup(&s[i], n);
			if (array[j] == NULL)
            {
                while (j-- >=  -1)
                    free(array[j + 1]);
				return (NULL);
            }
            i += n - 1;
			j++;
		}
		i++;
	}
	array[j] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;

	i = 0;
	array = (char **)malloc((ft_strlen(s) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	return (ft_split2(s, c, array, i));
}
