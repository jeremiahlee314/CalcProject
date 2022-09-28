#include "../include/linked_list.h"
#include <errno.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief creates a new list
 *
 * @param customfree pointer to the free function to be used with that list
 * @param compare_function pointer to the compare function to be used with that
 *        list. must
 * @returns pointer to allocated list on success or NULL on failure
 */
list_t *list_new(FREE_F freef, CMP_F cmpf)
{
    struct list_t *list = calloc(1, sizeof(struct list_t));
    if (NULL != list)
    {
        list->size = 0;
        list->head = NULL;
        list->tail = NULL;
        list->customfree = freef;
        list->compare_function = cmpf;
        return list;
    }
    return NULL;
}

/**
 * @brief checks if the list object is empty
 *
 * @param list pointer to linked list object to be checked
 * @returns non-zero if list is empty, 0 value if not empty
 */
int list_emptycheck(list_t *list)
{
    if (NULL != list)
    {
        if (list->size != 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    return -1;
}

/**
 * @brief pushes a new node onto the head of list
 *
 * @param list list to push the node into
 * @param data data to be pushed into node
 * @returns 0 on success, non-zero value on failure
 */
int list_push_head(list_t *list, void *data)
{
    struct list_node_t *node = calloc(1, sizeof(list_node_t));
    if (NULL != list && NULL != data && NULL != node)
    {
        node->data = data;
        node->position = 0;
        if (list_emptycheck(list))
        {
            node->next = NULL;
            node->prev = NULL;
            list->head = node;
            list->tail = node;
        }
        else
        {
            node->next = list->head;
            node->prev = list->tail;
            list->head->prev = node;
            list->head = node;
            list->tail->next = list->head;
            for (int index = 1; index < list->size; index++)
            {
                node = node->next;
                node->position++;
            }
        }
        list->size++;
        return 0;
    }
    free(node);
    node = NULL;
    return -1;
}

/**
 * @brief pushes a new node onto the tail of list
 *
 * @param list list to push the node into
 * @param data data to be pushed into node
 * @return 0 on success, non-zero value on failure
 */
int list_push_tail(list_t *list, void *data)
{
    struct list_node_t *node = calloc(1, sizeof(list_node_t));
    if (NULL != list && NULL != data && NULL != node)
    {
        node->data = data;
        node->position = list->size;
        if (list_emptycheck(list))
        {
            node->next = NULL;
            node->prev = NULL;
            list->tail = node;
            list->head = node;
        }
        else
        {
            list->tail->next = node;
            node->next = list->head;
            node->prev = list->tail;
            list->tail = node;
            list->head->prev = list->tail;
        }
        list->size++;
        return 0;
    }
    free(node);
    node = NULL;
    return -1;
    
}

/**
 * @brief pops the head node out of the list
 *
 * @param list list to pop the node out of
 * @return pointer to popped node on success, NULL on failure
 */
list_node_t *list_pop_head(list_t *list)
{
    if (NULL != list)
    {
        struct list_node_t *node = list->head;
        if (!list_emptycheck(list) && NULL != list->head)
        {
            list->size--;
            if (list_emptycheck(list))
            {
                node->next = NULL;
                node->prev = NULL;
                list->head = NULL;
                list->tail = NULL;
            }
            else
            {
                list->head = list->head->next;
                list->tail->next = list->head;
                list->head->prev = list->tail;
            }
            return node;
        }
    }
    return NULL;
}

/**
 * @brief pops the tail node out of the list
 *
 * @param list list to pop the node out of
 * @return pointer to popped node on success, NULL on failure
 */
list_node_t *list_pop_tail(list_t *list)
{
    if (NULL != list)
    {
        struct list_node_t *node = list->tail;
        if (!list_emptycheck(list) && NULL != list->tail)
        {
            list->size--;
            if (list_emptycheck(list))
            {
                node->next = NULL;
                node->prev = NULL;
                list->head = NULL;
                list->tail = NULL;
            }
            else
            {
                list->tail = node->prev;
                list->tail->next = list->head;
                list->head->prev = list->tail;
            }
            return node;
        }
    }
    return NULL;
}

/**
 * @brief get the data from the node at the head of the list without
 *        popping
 *
 * @param list list to pop the node out of
 * @return pointer to head node on success, NULL on failure
 */
list_node_t *list_peek_head(list_t *list)
{
    if (NULL != list)
    {
        return list->head;
    }
}

/**
 * @brief get the data from the node at the tail of the list without
 *        popping
 *
 * @param list list to pop the node out of
 * @return pointer to tail node on success, NULL on failure
 */
list_node_t *list_peek_tail(list_t *list)
{
    if (NULL != list)
    {
        return list->tail;
    }
}

/**
 * @brief remove a specific node from the list based on the data stored
 *        in that node
 *
 * @param list list to remove the node from
 * @param item_to_remove the data object to be searched for
 * @return 0 on success, non-zero value on failure
 */
int list_remove(list_t *list, void **item_to_remove)
{
    if (NULL != list && NULL != item_to_remove && NULL != *item_to_remove)
    {
        list_node_t *node = list->head;
        int size = list->size;
        while ((*(int *)node->data != *(int *)(item_to_remove)) && size > 0)
        {
            node = node->next;
            size--;
        }
        if (size > 0)
        {
            if (node->position > 0 && node->position < list->size - 1)
            {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            else if (node->position == 0)
            {
                list->head = node->next;
                list->head->prev = NULL;
            }
            else
            {
                list->tail = node->prev;
                list->tail->next = NULL;
            }
            free(node);
            node = NULL;
            list->size--;
            return 0;
        }
    }
    return -1;
}

/**
 * @brief perform a user defined action on the data contained in all of the
 *        nodes in list
 *
 * @param list list to perform actions on
 * @param action_function pointer to user defined action function
 * @return 0 on success, non-zero value on failure
 */
int list_foreach_call(list_t *list, ACT_F action_function)
{
    if (NULL != list)
    {
        list_node_t *node = list->head;
        for (int index = 0; index < list->size; index++)
        {
            action_function(node);
            node = node->next;
        }
        return 0;
    }
    return -1;
}

/**
 * @brief find the first occurrance of a node containing the search_data as
 *        found by the user defined compare function
 *
 * @param list list to search through
 * @param search_data is the pointer to the address of the data to be searched
 *                    for
 * @return pointer to node found on success, NULL on failure
 */
list_node_t *list_find_first_occurrence(list_t *list, void **search_data)
{
    if (NULL != list && NULL != search_data && NULL != *search_data)
    {
        list_node_t *node = list->head;
        int size = list->size;
        while ((*(int *)node->data != *(int *)(search_data)) && size > 0)
        {
            node = node->next;
            size--;
        }
        if (size > 0)
        {
            return node;
        }
    }
    return NULL;
}

/**
 * @brief find the first occurrance of a node containing the search_data as
 *        found by the user defined compare function
 *
 * @param list list to search through
 * @param receiving_list pointer to receiving list
 * @param search_data is the pointer to the address of the data to be searched
 *                    for
 * @return pointer to list of all found occurrecnces on success, NULL on failure
 */
list_t *list_find_all_occurrences(list_t *list, void **search_data)
{
    list_t *retlist = calloc(1, sizeof(struct list_t));
    if (NULL != list && NULL != retlist && NULL != search_data && NULL != *search_data && list->size > 0)
    {
        list_node_t *node = list->head;
        for (int index = 0; index < list->size; index++)
        {
            if (*(int *)node->data == *(int *)search_data)
            {
                list_push_head(retlist, node->data);
            }
            node = node->next;
        }
        return retlist;
    }
    list_clear(retlist);
    free(retlist);
    retlist = NULL;
    return NULL;
}

/**
 * @brief sort list as per user defined compare function
 *
 * @param list pointer to list to be sorted
 * @return 0 on success, non-zero value on failure
 */
int list_sort(list_t *list)
{
    if (NULL != list)
    {
        list_node_t *travnode = list->head;
        list_node_t *nexttrav = list->head->next;

        for (int moresort = 0; moresort < list->size; moresort++)
        {
            travnode = list->head;
            for (int listindex = 0; listindex < list->size; listindex++)
            {
                nexttrav = travnode->next;
                if (*(int *)travnode->data > *(int *)nexttrav->data)
                {
                    if (list->head == travnode)
                    {
                        list->head = nexttrav;
                        travnode->prev = nexttrav;
                        nexttrav->prev = list->tail;
                        travnode->next = nexttrav->next;
                        nexttrav->next = travnode;
                    }
                    else if (list->tail == nexttrav)
                    {
                        list->tail = travnode;
                        nexttrav->prev = travnode->prev;
                        nexttrav->next = travnode;
                        travnode->prev->next = nexttrav;
                        travnode->prev = nexttrav;
                        travnode->next = list->head;
                        break;
                    }
                    else
                    {
                        travnode->prev->next = nexttrav;
                        nexttrav->next->prev = travnode;
                        nexttrav->prev = travnode->prev;
                        travnode->next = nexttrav->next;
                        travnode->prev = nexttrav;
                        nexttrav->next = travnode;
                    }
                }
                else
                {
                    travnode = travnode->next;
                    break;
                }
            }
        }
        return 0;
    }
    return -1;
}

/**
 * @brief clear all nodes out of a list
 *
 * @param list list to clear out
 * @return 0 on success, non-zero value on failure
 */
int list_clear(list_t *list)
{
    if (NULL != list)
    {
        list_node_t *node = list->head;
        for (int index = 0; index < list->size; index++)
        {
            list_node_t *clearnode = node;
            node = node->next;
            free(clearnode);
            clearnode = NULL;
        }
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
        return 0;
    }
    return -1;
}

/**
 * @brief delete a list
 *
 * @param list_address pointer to list pointer
 * @return 0 on success, non-zero value on failure
 */
int list_delete(list_t **list_address)
{
    if (NULL != list_address && NULL != *list_address)
    {
        list_clear(*list_address);
        free(*list_address);
        *list_address = NULL;
        return 0;
    }
    return -1;
}

/**
 * @brief frees an item and its associated memory
 *
 * @param mem_addr pointer of the item to be free'd
 */
void custom_free(void *mem_addr)
{
    if (NULL != mem_addr)
    {
        free(mem_addr);
        mem_addr = NULL;
    }
}