#include "sort.h"

/**
 * insertion_sort_list - insertion sort
 * @list: Double pointer to the head of the linked list
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *head, *temp, *current, *prev;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    head = *list;
    current = head->next;

    while (current != NULL)
    {
        temp = current;

        while (temp->prev != NULL && temp->n < temp->prev->n)
        {
            prev = temp->prev;

            prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = prev;

            temp->prev = prev->prev;
            temp->next = prev;

            if (prev->prev != NULL)
                prev->prev->next = temp;
            else
                head = temp;

            prev->prev = temp;

            print_list(head);

            temp = prev;
        }

        current = current->next;
    }

    *list = head;
}
