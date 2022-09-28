#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief structure of a queue node
 *
 * @param data void pointer to whatever data that queue points to
 */
typedef struct queue_node_t
{
    void *data;
} queue_node_t;

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
 * @param customfree is a FREE_F pointer to a user defined free function
 * @param arr is the array containing the queue node pointers
 *
 */
typedef struct queue_t
{
    uint32_t capacity;
    uint32_t currentsz;
    FREE_F customfree;
    queue_node_t **arr;
} queue_t;

/**
 * @brief creates a new queue
 *
 * @param capacity max number of nodes the queue will hold
 * @param custmfree pointer to user defined free function
 * @note if the user passes in NULL, the queue should default to using free()
 * @returns the 0 on success, non-zero value on failure
 */
queue_t *queue_init(uint32_t capacity, FREE_F customfree)
{
    struct queue_t *queue = calloc(1, sizeof(struct queue_t));
    queue->arr = calloc(capacity, sizeof(struct queue_node_t *));
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
int queue_fullcheck(queue_t *queue)
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
int queue_emptycheck(queue_t *queue)
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
 * @return the 0 on success, non-zero value on failure
 */
int queue_enqueue(queue_t *queue, void *data)
{
    queue_node_t *node = calloc(1, sizeof(queue_node_t));
    if (queue != NULL && data !=NULL && node != NULL && !queue_fullcheck(queue))
    {
        node->data = data;
        queue->arr[queue->currentsz] = node;
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
 * @return the 0 on success, non-zero value on failure
 */
queue_node_t *queue_dequeue(queue_t *queue)
{
    queue_node_t *node = NULL;
    if (queue != NULL && queue_emptycheck(queue) == 0)
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
 * @return the pointer to the head on success or NULL for failure
 */
queue_node_t *queue_peek(queue_t *queue)
{
    if (queue != NULL && !queue_emptycheck(queue))
    {
        return queue->arr[0];
    }
    return NULL;
}

/**
 * @brief clear all nodes out of a queue
 *
 * @param queue pointer to queue pointer to clear out
 * @return the 0 on success, non-zero value on failure
 */
int queue_clear(queue_t *queue)
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
 * @param queue_addr pointer to address of queue to be destroyed
 * @return the 0 on success, non-zero value on failure
 */
int queue_destroy(queue_t **queue_addr)
{
    if (queue_addr != NULL && *queue_addr != NULL)
    {
        queue_clear(*queue_addr);
        free((*queue_addr)->arr);
        (*queue_addr)->arr = NULL;
        free ((*queue_addr));
        *queue_addr = NULL;
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