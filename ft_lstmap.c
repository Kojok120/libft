/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:23:41 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/27 18:10:59 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *newlst;
    t_list  *current;

    newlst = NULL;
    while (lst != NULL)
    {
        current = ft_lstnew(f(lst->content));
        if (current == NULL)
        {
            ft_lstclear(&newlst, del);
            return (NULL);
        }
        ft_lstadd_back(&newlst, current);
        lst = lst->next;
    }
    return (newlst);
}
