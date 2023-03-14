#include <stdlib.h>
#include "ft_list_h"

t_list  *ft_create_elem(void *data)
{
    t_list  *list_element;
    
    list_element = malloc(sizeof(t_list))
    if (!list_element)
        return  (NULL);
    
    list_element->data = malloc(sizeof(void *));
    if (list_element->data == NULL)
        return (NULL);
    list_element->next = malloc(sizeof(t_list *));
    if (list_element->next == NULL)
        return (NULL);
   
    list_element->data = data;
    list_element->next = NULL;
    return (list_element);
}
