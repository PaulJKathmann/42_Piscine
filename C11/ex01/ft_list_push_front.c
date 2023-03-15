#include "ft_list.h"
#include <stdio.h>

void  ft_list_push_front(t_list **begin_list, void *data)
{
    t_list  *list_element;
    
    list_element = ft_create_elem(data);
    list_element->next = *begin_list;
    *begin_list = list_element;
}

int main(void)
{
    char *str = "Test";
    char *str1 = "Test2";
    
    t_list *list_element = ft_create_elem(str);
    t_list **full_list = &list_element;
    
    ft_list_push_front(full_list, str1);
    
    printf("element 1: %s\n", (char *)(*full_list)->data);
    printf("element 2: %s\n", (char *)(*full_list)->next->data);
}
