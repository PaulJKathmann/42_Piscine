
#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list {
    void   *data;
    struct s_list *next;
} t_list;

#include <stdlib.h>

t_list  *ft_create_elem(void *data)
{
    t_list  *list_element;
    
    list_element = malloc(sizeof(t_list));
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

#include <stdio.h>

void  ft_list_push_front(t_list **begin_list, void *data)
{
    t_list  *list_element;
    
    list_element = ft_create_elem(data);
    list_element->next = *begin_list;
    *begin_list = list_element;
}

#endif
