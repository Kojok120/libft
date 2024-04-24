
#include "libft.h"

void    ft_lstadd_front(t_list **lst, t_list *new)
{
    t_list *ndptr;

    ndptr =  new;
    ndptr -> next = *lst;
    *lst = ndptr;
}
