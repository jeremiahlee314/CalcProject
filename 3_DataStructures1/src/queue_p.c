#ifndef _QUEUE_P_H
#define _QUEUE_P_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief structure of a queue node
 *
 * @param data      void pointer to whatever data that queue points to
 * @param priority  priority to add to q; higher priority gets preference in q
 */
typedef struct queue_p_node_t
{
    void *data;
    int priority;
} queue_p_node_t;

/**
 * @brief A pointer to a user-defined free function.  This is used to free
 *        memory allocated for queue data.  For simple data types, this is
 *        just a pointer to the standard free function.  More complex structs
 *        stored in queues may require a function that calls free on multiple
 *        components.
 *
 */
typedef void (*FREE_F)(void *);

/**
 * @brief structure of a queue object
 *
 * @param capacity is the number of nodes the queue can hold
 * @param currentsz is the number of nodes the queue is currently storing
 * @param arr is the array containing the queue node pointers
 * @param customfree pointer to the user defined free function
 */
typedef struct queue_p_t
{
    uint32_t capacity;
    uint32_t currentsz;
    queue_p_node_t **arr;
    FREE_F customfree;
} queue_p_t;

/**
 * @brief creates a new queue
 *
 * @param capacity max number of nodes the queue will hold
 * @param customfree pointer to the free function to be used with that list
 *        list
 * @returns pointer to allocated priority queue on success, NULL on failure
 */
queue_p_t *queue_p_init(uint32_t capacity, FREE_F customfree)
{
    struct queue_p_t *queue = calloc(1, sizeof(struct queue_p_t));
    queue->arr = calloc(capacity, sizeof(struct queue_node_p_t *));
    if (NULL != queue && queue->arr != NULL)
    {
        queue->capacity = capacity;
        queue->customfree = customfree;
        queue->currentsz = 0;
    }

    return queue;
}

/**
 * @brief verifies that queue isn't full
 *
 * @param queue pointer queue object
 * @return 0 on success, non-zero value on failure
 */
int queue_p_fullcheck(queue_p_t *queue)
{
    if (queue->capacity == queue->currentsz)
    {
        return -1;
    } 
    else 
    {
        return 0;
    }
}

/**
 * @brief verifies that queue isn't empty
 *
 * @param queue pointer queue object
 * @return 0 on success, non-zero value on failure
 */
int queue_p_emptycheck(queue_p_t *queue)
{
    if (queue != NULL)
    {
        if (queue->currentsz > 0)
        {
            return 0;
        }
    }
    return -1;
}

/**
 * @brief pushes a new node into the queue
 *
 * @param queue pointer to queue pointer to push the node into
 * @param data data to be pushed into node
 * @param priority of data
 * @return 0 on success, non-zero value on failure
 */
int queue_p_enqueue(queue_p_t *queue, void *data, int priority)
{
    queue_p_node_t *node = calloc(1, sizeof(queue_p_node_t));
    if (queue != NULL && data !=NULL && node != NULL && !queue_p_fullcheck(queue))
    {
        node->data = data;
        node->priority = priority;
        if (queue_p_emptycheck(queue))
        {
            queue->arr[queue->currentsz] = node;
        }
        else
        {
            int index = 0;
            while (index < queue->currentsz && node->priority <= queue->arr[index]->priority)
            {
                index++;
            }
            
            for (int shuffle = queue->currentsz; shuffle > index; shuffle--)
            {
                queue->arr[shuffle] = queue->arr[shuffle-1];
            }
            queue->arr[index] = node;
        }
        queue->currentsz++;
        return 0;
    }
    else
    {
        free(node);
        node = NULL;
    }
    return -1;
}

/**
 * @brief pops the front node out of the queue
 *
 * @param queue pointer to queue pointer to pop the node off of
 * @return pointer to popped queue node on success, NULL on failure
 */
queue_p_node_t *queue_p_dequeue(queue_p_t *queue)
{
    queue_p_node_t *node = NULL;
    if (queue != NULL && queue_p_emptycheck(queue) == 0)
    {
        node = queue->arr[0];
        int i = 0;
        do
        {
            queue->arr[i] = queue->arr[i+1];
            i++;
        } while (i < queue->capacity-1 && queue->arr[i] != NULL); 
        
        queue->arr[i] = NULL;
        queue->currentsz--;
        return node;
    }
    return node;
}

/**
 * @brief get the data from the node at the front of the queue without popping
 *
 * @param queue pointer to queue pointer to peek
 * @return pointer to popped queue node on success, NULL on failure
 */
queue_p_node_t *queue_p_peek(queue_p_t *queue)
{
    if (queue != NULL && !queue_p_emptycheck(queue))
    {
        return queue->arr[0];
    }
    return NULL;
}

/**
 * @brief clear all nodes out of a queue
 *
 * @param queue pointer to queue pointer to clear out
 * @return 0 on success, non-zero value on failure
 */
int queue_p_clear(queue_p_t *queue)
{
    if (queue != NULL)
    {
        for (int i = 0; i < queue->capacity; i++)
        {
            free(queue->arr[i]);
            queue->arr[i] = NULL;
        }
        queue->currentsz = 0;
        return 0;
    }
    return -1;
}

/**
 * @brief delete a queue
 *
 * @param queue pointer to queue pointer to be destroyed
 * @return 0 on success, non-zero value on failure
 */
int queue_p_destroy(queue_p_t **queue)
{
    if (queue != NULL && *queue != NULL)
    {
        queue_p_clear(*queue);
        free((*queue)->arr);
        (*queue)->arr = NULL;
        free ((*queue));
        *queue = NULL;
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
    free(mem_addr);
    mem_addr = NULL;
}
#endif
