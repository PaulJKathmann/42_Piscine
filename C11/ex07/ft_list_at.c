#include "ft_list.h"

t_list  *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    unsigned int i;
    
    i = 0;
    while (i < nbr) {
        if (begin_list->next)
            begin_list = begin_list->next;
        else
            return (NULL);
        i++;
    }
    return (begin_list);
}

int main(void)
{
    char    *str1 = "Hello World";
    char    *str2 = "Second String";
    char    *str3 = "Third String";
    t_list  *list_elem = ft_create_elem(str1);
    t_list  **full_list = &list_elem;
    
    ft_list_push_front(full_list, str2);
    ft_list_push_front(full_list, str3);

    printf("2th element is: %s\n", (char *)ft_list_at(*full_list, 1) ? (char *)ft_list_at(*full_list, 1)->data : NULL);
}
