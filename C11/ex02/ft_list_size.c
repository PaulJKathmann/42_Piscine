#include "ft_list.h"



int ft_list_size(t_list *begin_list)
{
    int size;
    t_list *list_element;
    
    size = 1;
    list_element = begin_list;
    while (list_element->next) {
        list_element = list_element->next;
        size++;
    }
    
    return (size);
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

    
    printf("size of list: %d\n", ft_list_size(*full_list));
}
