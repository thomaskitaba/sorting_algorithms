#include "sort.h"
/**
* insertion_sort_list - insertion sort
* @array: array
* @size: size  of array
*/

void insertion_sort_list(listint_t **list)
{
listint_t *head, *temp, *head_o, *head_i;
head = temp = head_o = *list;
head_i = NULL;

while (head_o)
{
    head_i = head_o;
    if (head_o->prev != NULL)
    {
        while(head_i->n < head_i->prev->n || head_i->prev != NULL)
        {
            temp = head_i;

            if (head_i->next == NULL)
                {
                    head_i->prev->next = NULL;
                }
            else
                head_i->prev->next = head_i->next;
            if (head_i->prev->prev != NULL)
            {
                head_i->prev->prev = head_i;
                head_i->prev->prev->next = head_i;
                head_i->prev = head_i->prev->prev;
            }
            else
            {
                head_i->prev = NULL;
                head_i->next = head_i->prev;

            }






            print_list(head);
            head_i = head_i->prev;
        }
    head_o = head_o->next;
    }
}

}
