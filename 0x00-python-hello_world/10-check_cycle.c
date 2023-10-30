#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: pointer to the head of the linked list
 * Return: 1 if there is a cycle, 0 if there is no cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *slow, *fast;

    if (list == NULL)
        return (0);

    slow = list;
    fast = list;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;          // Move slow one step
        fast = fast->next->next;    // Move fast two steps

        if (slow == fast)
            return (1);  // If they meet, there's a cycle
    }

    return (0);  // If fast reaches the end, there's no cycle
}

