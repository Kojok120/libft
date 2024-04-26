/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:26:35 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/26 23:21:37 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;
	size_t	haystack_len;

	i = 0;
	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	if (needle_len == 0)
		return ((char *)&haystack[0]);
	if (len == 0 || len < needle_len || haystack_len == 0)
		return (NULL);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (i + j < len && haystack[i + j] == needle[j] && needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//     char haystack[30] = "aaabcabcd";
//     char needle[10] = "aabc";

//     printf("ft    : %p\n", ft_strnstr(haystack, needle, 20));
//     printf("origin    : %p\n", strnstr(haystack, needle, 20));
//     printf("ft    : %p\n", ft_strnstr(0, "fake", 3));
//     printf("origin: %p\n", strnstr(0, "fake", 3));
//     printf("ft    : %p\n", ft_strnstr("fake", 0, 3));
//     printf("origin: %p\n", strnstr("fake", 0, 3));
//     printf("ft    : %p\n", ft_strnstr(haystack, needle, -1));
//     printf("origin    : %p\n", strnstr(haystack, needle, -1));
// }