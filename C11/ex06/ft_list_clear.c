#include "ft_list.h"

void    ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    t_list *tmp_ptr;
    
    while (begin_list->next) {
        tmp_ptr = begin_list;
        begin_list = begin_list->next;
        free(tmp_ptr->next);
        free_fct(tmp_ptr->data);
    }
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

    ft_list_clear(*full_list, free_fct());
}
