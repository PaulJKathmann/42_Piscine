#include "ft_list.h"

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (list_ptr) {
        (*f)(list_ptr->data);
        list_ptr = list_ptr->next;
    }
}
