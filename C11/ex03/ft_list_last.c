#include "ft_list.h"

t_list *ft_list_last(t_list *begin_list)
{
    
    while (begin_list->next)
        begin_list = begin_list->next;
    return (begin_list);
}

int main(void)
{
    char *str = "Test";
    char *str1 = "Test2";
    char *str2 = "Test3";

    
    t_list *list_element = ft_create_elem(str);
    t_list **full_list = &list_element;
    
    ft_list_push_front(full_list, str1);
    ft_list_push_front(full_list, str2);

    
    printf("last element in list: %s\n", (char *)ft_list_last(*full_list)->data);
}
