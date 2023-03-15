#include "ft_list.h"

void    ft_list_push_back(t_list **begin_list, void *data)
{
    t_list *list_element;
    
    list_element = *begin_list;
    while (list_element->next) {
        list_element = list_element->next;
    }
    list_element->next = ft_create_elem(data);
}

int main(void)
{
    char *str = "Test";
    char *str1 = "Test2";
    char *str2 = "Test3";
    char *str3 = "Test4";

    
    t_list *list_element = ft_create_elem(str);
    t_list **full_list = &list_element;
    
    ft_list_push_front(full_list, str1);
    ft_list_push_front(full_list, str2);

    ft_list_push_back(full_list, str3);
    
    printf("last element in list: %s\n", (char *)ft_list_last(*full_list)->data);
}
