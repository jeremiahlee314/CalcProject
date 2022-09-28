#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "../../3_DataStructures1/include/queue.h"



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
 * @brief structure of a threadpool object
 *
 * @param capacity is the number of nodes the queue can hold
 * @param currentsz is the number of nodes the queue is currently storing
 * @param customfree is a FREE_F pointer to a user defined free function
 * @param arr is the array containing the queue node pointers
 *
 */
typedef struct threadpool_t
{
    uint32_t threadcapacity;
    uint32_t workcapacity;
    uint16_t terminate;
    queue_t *queue;
    pthread_t **pool;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    FREE_F customfree;
} threadpool_t;


/*
 * @brief creates a new queue
 *
 * @param capacity max number of nodes the queue will hold
 * @param custmfree pointer to user defined free function
 * @note if the user passes in NULL, the queue should default to using free()
 * @returns the 0 on success, non-zero value on failure
 */
threadpool_t *threadpool_init(uint32_t threadcapacity, uint32_t workcapacity, void *workfunction(void *param), void *param);

void push_work(threadpool_t *threadpool, void *data);

void * pull_work(threadpool_t *threadpool);

int join_threads(threadpool_t *threadpool);



/**
 * @brief frees an item and its associated memory
 *
 * @param mem_addr pointer of the item to be free'd
 */
void threadpool_free(threadpool_t *threadpool);

void terminate_threadpool(threadpool_t * threadpool);


#endif
