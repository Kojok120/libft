#include "libft.h"

void    ft_lstdelone(t_list *lst, void (*del)(void *))
{
    t_list    *cnt;

    cnt = lst -> content;
    del(cnt);
    free(lst);
}