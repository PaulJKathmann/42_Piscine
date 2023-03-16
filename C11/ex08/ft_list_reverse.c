#include "ft_list.h"

void    ft_reverse(t_list *prev_elem, t_list *current_elem)
{
    if (current_elem->next)
        ft_reverse(current_elem, current_elem->next);
    current_elem->next = prev_elem;
}

void    ft_list_reverse(t_list **begin_list)
{
    t_list *temp;
    t_list *list_elem;
    
    list_elem = *begin_list;
    while (list_elem->next)
        list_elem = list_elem->next;
    temp = list_elem;
    ft_reverse(NULL, *begin_list);
    *begin_list = temp;
}

int main(void)
{
    char    *str1 = "Third";
    char    *str2 = "Second";
    char    *str3 = "First";
    t_list  *list_elem = ft_create_elem(str1);
    t_list  **full_list = &list_elem;
    t_list  *tmp;
    
    ft_list_push_front(full_list, str2);
    ft_list_push_front(full_list, str3);

    ft_list_reverse(full_list);
    tmp = *full_list;
    while (tmp->next) {
        printf("%s\n", (char *)tmp->data);
        tmp = tmp->next;
    }
    printf("%s\n", (char *)tmp->data);
}
