#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "../include/threadpool.h"
#include "../../3_DataStructures1/include/queue.h"

/**
 * @brief creates a new threadpool
 *
 * @param threadcapacity number of threads the pool will hold
 * @param workcapacity number of jobs the queue will hold
 * @param workfunction threadfucntion that the user provides; aka jobs for the threads
 * @param param parameter for the work function. can be NULL
 * @return NULL if failure, threadpool_t * if successful
 */

threadpool_t *threadpool_init(uint32_t threadcapacity, uint32_t workcapacity, void *workfunction(void *param), void *param)
{
    queue_t *queue = queue_init(workcapacity, NULL);
    threadpool_t *threadpool = calloc(1, sizeof(struct threadpool_t));
    if (NULL != threadpool && NULL != queue)
    {
        threadpool->pool = calloc(threadcapacity, sizeof(pthread_t *));
        if (NULL != threadpool->pool)
        {
            threadpool->queue = queue;
            threadpool->threadcapacity = threadcapacity;
            threadpool->workcapacity = workcapacity;
            threadpool->terminate = 0;
            if (pthread_mutex_init(&(threadpool->mutex), NULL) !=0)
            {
                printf("\n\nFailed to init mutex\n\n");
            }
            if (pthread_cond_init(&(threadpool->cond), NULL) !=0)
            {
                printf("\n\nFailed to init cond\n\n");
            }
            for (int i = 0; i < threadcapacity; i++)
            {
                threadpool->pool[i] = malloc(sizeof(pthread_t));
                pthread_create(threadpool->pool[i], NULL, workfunction, param);
            }
            return threadpool;
        }
        return NULL;
    }
    return NULL;
}

/**
 * @brief push work onto workload queue
 * 
 * @param threadpool 
 * @param data 
 */
void push_work(threadpool_t *threadpool, void *data)
{
    if (NULL != data && NULL != threadpool)
    {
        pthread_mutex_lock(&(threadpool->mutex));
        queue_enqueue(threadpool->queue, data);
        pthread_mutex_unlock(&(threadpool->mutex));
        pthread_cond_broadcast(&(threadpool->cond));

    }
}

/**
 * @brief pull work from the workload queue
 * 
 * @param threadpool 
 * @return void* 
 */
void *pull_work(threadpool_t *threadpool)
{
    void *data = NULL;
    pthread_mutex_lock(&(threadpool->mutex));
    if (!queue_emptycheck(threadpool->queue))
    {
        queue_node_t *node = queue_dequeue(threadpool->queue);
        data = node->data;
        free(node);
        node = NULL;
    }
    else
    {
        if (!threadpool->terminate)
        {
            pthread_cond_wait(&(threadpool->cond), &(threadpool->mutex));
        }
    }
    pthread_mutex_unlock(&threadpool->mutex);
    return data;
}

/**
 * @brief user doesnt need to call this. Just call terminate.
 * 
 * @param threadpool 
 */
int join_threads(threadpool_t *threadpool)
{
    int retval = 0;
    if (NULL != threadpool)
    {
        for (int i = 0; i < threadpool->threadcapacity; i++)
        {
            pthread_cond_broadcast(&threadpool->cond);
            if (pthread_join(*(threadpool->pool[i]), NULL))
            {
                printf("Failed to join on thread: %ld\n", *(threadpool->pool[i]));
            }
            else
            {
                free(threadpool->pool[i]);
                threadpool->pool[i] = NULL;
            }
        }
        retval = 1;
    }
    return retval;
}

/**
 * @brief user doesnt need to call this. Just call terminate.
 * 
 * @param threadpool 
 */
void threadpool_free(threadpool_t *threadpool)
{
    free(threadpool->pool);
    threadpool->pool = NULL;
    free(threadpool);
    threadpool = NULL;
}

/**
 * @brief signals threadpool to terminate and cleans up memory allocs
 * 
 * @param threadpool 
 */
void terminate_threadpool(threadpool_t *threadpool)
{
    threadpool->terminate = 1;
    join_threads(threadpool);
    queue_destroy(&threadpool->queue);
    threadpool_free(threadpool);
}