/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:23:41 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/24 20:05:59 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    // t_list	*newlist;

	// newlist = malloc(sizeof(t_list));
	// if (newlist == NULL)
	// 	return (NULL);
	// while (lst != NULL)
	// {
	// 	f(lst->content);
	// 	lst = lst->next;
	// }

    f(lst);
    del(lst);
    return (lst);
}
