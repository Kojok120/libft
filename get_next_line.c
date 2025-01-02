/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:18:19 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/02 13:19:39 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*array;

	if (!s1 || !s2)
		return (NULL);
	array = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!array)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		array[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		array[i] = s2[j];
		j++;
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	*init_memory(char **memo)
{
	char	*memory;

	if (!*memo)
		*memo = ft_strdup("");
	memory = (char *)malloc(BUFFER_SIZE + 1);
	if (!memory)
		return (NULL);
	return (memory);
}

char	*read_line(int fd, char **memo)
{
	char	*buf;
	ssize_t	ret;
	char	*temp;

	buf = init_memory(memo);
	if (!buf)
		return (NULL);
	ret = 1;
	while (!ft_strchr(*memo, '\n') && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			free(buf);
			free(*memo);
			*memo = NULL;
			return (NULL);
		}
		buf[ret] = '\0';
		temp = ft_strjoin(*memo, buf);
		free(*memo);
		*memo = temp;
	}
	free(buf);
	return (*memo);
}

char	*extract_line(char **memo)
{
	char	*line;
	char	*temp;

	if (!ft_strchr(*memo, '\n'))
	{
		if (**memo == '\0')
		{
			free(*memo);
			*memo = NULL;
			return (NULL);
		}
		line = ft_strdup(*memo);
		free(*memo);
		*memo = NULL;
	}
	else
	{
		line = ft_substr(*memo, 0, ft_strchr(*memo, '\n') - *memo + 1);
		temp = ft_strdup(ft_strchr(*memo, '\n') + 1);
		free(*memo);
		*memo = temp;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*memo[OPEN_MAX];

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_line(fd, &memo[fd]) == NULL)
		return (NULL);
	return (extract_line(&memo[fd]));
}
