#include "ft_list.h"

t_list *ft_list_push_strs(int size, char **strs)
{
    t_list  *list_element;
    t_list  *temp;
    int     i;
    
    list_element = ft_create_elem(strs[0]);
    i = 1;
    while (i < size) {
        temp = ft_create_elem(strs[i]);
        temp->next = list_element;
        list_element = temp;
        i++;
    }
    return (list_element);
}

int main(void)
{
    char    **strs;
    int     i;
    strs = malloc(sizeof(char *) * 4);
    for (i = 0; i < 4; i++) {
        strs[i] = malloc(sizeof(char) * 4);
        strs[i][0] = '0' + i;
    }
    
    t_list *f_list = ft_list_push_strs(4, strs);
    
    printf("1: %s\n", (char *)f_list->data);
    printf("2: %s\n", (char *)f_list->next->data);
    printf("3: %s\n", (char *)f_list->next->next->data);
    printf("4: %s\n", (char *)f_list->next->next->next->data);
}
