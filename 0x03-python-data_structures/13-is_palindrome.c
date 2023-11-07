#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - Check if a singly linked list is a palindrome
 * @head: Pointer to the head of the linked list
 * Return: 1 if the list is a palindrome, 0 if it is not
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head;
    listint_t *prev = NULL, *temp, *mid = NULL;
    int is_palindrome = 1;

    if (*head == NULL || (*head)->next == NULL)
        return 1;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        temp = slow;
        slow = slow->next;
        temp->next = prev;
        prev = temp;
    }

    if (fast != NULL)
    {
        mid = slow;
        slow = slow->next;
    }

    while (prev != NULL)
    {
        if (prev->n != slow->n)
        {
            is_palindrome = 0;
            break;
        }
        prev = prev->next;
        slow = slow->next;
    }

    while (mid != NULL)
    {
        temp = prev;
        prev = mid;
        mid = mid->next;
        prev->next = temp;
    }

    return is_palindrome;
}

