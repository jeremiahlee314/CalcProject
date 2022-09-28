#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/hash_table.h"

#define MAX_STRING 16

/**
 * @brief initializes hash table
 * 
 * @param size number indexes in the table
 * 
 * @return hash_table_t pointer to allocated table
 */
hash_table_t *hash_table_init(uint32_t size, FREE_F customfree)
{
    hash_table_t *hashtable = calloc(1, sizeof(struct hash_table_t));
    if (NULL != hashtable)
    {
        hashtable->table = calloc(size, sizeof(struct node_t *));
        if (NULL != hashtable->table)
        {
            hashtable->size = size;
            if (NULL == customfree)
            {
                hashtable->customfree = free;
            }
            else
            {
                hashtable->customfree = customfree;
            }
            return hashtable;
        }
        else
        {
            free(hashtable->table);
            hashtable->table = NULL;
            free(hashtable);
            hashtable = NULL;
            return NULL;
        }
    }
    else
    {
        free(hashtable);
        hashtable = NULL;
        return NULL;
    }
}

/**
 * @brief adds an item to the table
 *
 * @param table pointer to table address
 * @param data data to be stored at that key value
 * @param key key for data to be stored at
 *
 * @return int exit code
 */
int hash_table_add(hash_table_t *table, void *data, char *key)
{
    if (NULL != table && NULL != data && NULL != key)
    {
        int hashedval = 0;
        for (int hasher = 0; hasher < strnlen(key, MAX_STRING); hasher++)
        {
            hashedval += (int)key[hasher];
        }
        hashedval = hashedval % table->size;

        node_t *node = calloc(1, sizeof(struct node_t));
        if (NULL != node)
        {
            node->key = calloc(1, MAX_STRING);
            if (NULL != node->key)
            {
                node->data = data;
                strncpy(node->key, key, MAX_STRING);
                node->next = NULL;

                if (NULL == table->table[hashedval])
                {
                    table->table[hashedval] = node;
                }
                else
                {
                    node_t *travnode = table->table[hashedval];
                    while (NULL != travnode->next)
                    {
                        travnode = travnode->next;
                    }
                    travnode->next = node;
                }
                return 0;
            }
            else
            {
                free(node->key);
                node->key = NULL;
                free(node);
                node = NULL;
            }
        }
        else
        {
            free(node);
            node = NULL;
        }
    }
    return 1;
}

/**
 * @brief looks up an item in the table by key
 *
 * @param table pointer to table address
 * @param key key for data being searched for
 *
 * @return void * data
 */
void *hash_table_lookup(hash_table_t *table, char *key)
{
    if (NULL != table && NULL != key)
    {
        int hashedval = 0;
        for (int hasher = 0; hasher < strnlen(key, MAX_STRING); hasher++)
        {
            hashedval += (int)key[hasher];
        }
        hashedval = hashedval % table->size;
        if (NULL != table->table[hashedval])
        {
            node_t *travnode = table->table[hashedval];
            while (strncmp(travnode->key, key, MAX_STRING) != 0)
            {
                if (NULL != travnode->next)
                {
                    travnode = travnode->next;
                }
                else
                {
                    return NULL;
                }
            }
            return travnode->data;
        }
    }
    return NULL;
}

/**
 * @brief removes an item from the hash table
 *
 * @param table pointer to table address
 * @param key key of data to be removed
 *
 * @return int
 */
int hash_table_remove(hash_table_t *table, char *key)
{
    if (NULL != table && NULL != key)
    {
        int hashedval = 0;
        for (int hasher = 0; hasher < strnlen(key, MAX_STRING); hasher++)
        {
            hashedval += (int)key[hasher];
        }
        hashedval = hashedval % table->size;

        if (NULL != table->table[hashedval])
        {
            node_t *travnode = table->table[hashedval];
            if (strncmp(travnode->key, key, MAX_STRING) == 0)
            {
                table->table[hashedval] = travnode->next;
                free(travnode->key);
                travnode->key = NULL;
                free(travnode);
                travnode = NULL;
            }
            else
            {
                while (NULL != travnode->next && strncmp(travnode->next->key, key, MAX_STRING) != 0)
                {
                    travnode = travnode->next;
                }
                if (NULL == travnode->next)
                {
                    return 1;
                }
                else
                {
                    node_t *freenode = travnode->next;
                    travnode->next = freenode->next;
                    free(freenode->key);
                    freenode->key = NULL;
                    free(freenode);
                    freenode = NULL;
                }
            }
            return 0;
        }
    }
    return 1;
}

/**
 * @brief clears all data from hash table
 *
 * @param table_addr pointer to address of table to be cleared out
 *
 * @return int
 */
int hash_table_clear(hash_table_t *table)
{
    if (NULL != table)
    {
        for (int tableindex = 0; tableindex < table->size; tableindex++)
        {
            if (NULL != table->table[tableindex])
            {
                node_t *node = table->table[tableindex];
                if (NULL != node->next)
                {
                    while (NULL != node->next)
                    {
                        node_t *freenode = node;
                        node = node->next;
                        free(freenode->key);
                        freenode->key = NULL;
                        free(freenode);
                        freenode = NULL;
                    }
                    free(node->key);
                    node->key = NULL;
                    free(node);
                    node = NULL;
                }
                else
                {
                    free(node->key);
                    node->key = NULL;
                    free(node);
                    node = NULL;
                }
            }
        }
        return 0;
    }
    return 1;
}

/**
 * @brief destroys hash table
 *
 * @param table_addr pointer to table address
 * @return int
 */
int hash_table_destroy(hash_table_t **table_addr)
{
    if (NULL != table_addr && NULL != *table_addr)
    {
        free((*table_addr)->table);
        (*table_addr)->table;
        free(*table_addr);
        *table_addr = NULL;
        return 0;
    }
    return 1;
}

/**
 * @brief frees an item and its associated memory
 *
 * @param mem_addr pointer of the item to be free'd
 */
void custom_free(void *mem_addr)
{
    free(mem_addr);
}
