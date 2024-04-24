#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    int i;
    t_list  *lst2;
    
    i = 0;
    lst2 = NULL;
    while (lst != NULL)
    {
        lst2 = lst;
        lst = lst -> next;
        i++;
    }
    return (lst2);
}