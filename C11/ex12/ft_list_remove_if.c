#include "ft_list.h"

void    free_fct(void *data)
{
    free(data);
}

int cmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return (s1[i] - s2[i]);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
    t_list *tmp;
    t_list *prev_list;
    t_list *list_start;
    
    list_start = *begin_list;
    while (list_start) {
        if (cmp(list_start->data, data_ref) == 0)
        {
            printf("Test");
            tmp = list_start->next;
            free_fct(list_start->data);
            free(list_start);
            prev_list->next = tmp;
            list_start = tmp;
        }
        else
        {
            prev_list = list_start;
            list_start = list_start->next;
        }
    }
}

int main(void)
{
    char    *str1 = "Hello World";
    char    *str2 = "Second String";
    char    *str3 = "Third String";
    char    *str_ref = "Second String";
    t_list  *list_elem = ft_create_elem(str1);
    t_list  **full_list = &list_elem;
    t_list  *new_list;
    
    ft_list_push_front(full_list, str2);
    ft_list_push_front(full_list, str3);
 
    ft_list_remove_if(full_list, str_ref, &cmp, &free_fct);
    new_list = *full_list;
    while (new_list) {
        printf("%s\n", (char *)new_list->data);
        new_list = new_list->next;
    }
}
