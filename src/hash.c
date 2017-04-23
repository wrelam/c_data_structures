/***************************************************************************//**
    @file   hash.c

    @brief  Implementation of a hash table
*******************************************************************************/
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list_doubly.h"
#include "hash.h"

typedef dll_list HashChain;

struct HashTable {
    size_t chainCount;
    size_t recCount;
    size_t recLimit;
    HashChain *chains;
};


/* Approximately how many elements each chain will hold */
#define HASH_CHAIN_LEN  (10)

/* List of primes that approximate powers of 2, used for growing the table */
static size_t tableSizes[] = {
    127, 257, 509, 1021, 2053, 4099, 8191, 16381, 32771, 131071
};

/*******************************************************************************
    ht_create_rec
*//**
    @brief  Creates a new hash record containing the provided data
    @param  key     Record key
    @param  *val    Record value
    @param  val_len Length of val

    If the record is never put into a table then the caller is responsible for
    destroying this node with ht_destroy_record().

    @see    ht_destroy_record()

    @return New record
    @retval NULL    No record could be created
*******************************************************************************/
HashRecord *
ht_create_rec(HashKey key, void *val, size_t val_len)
{
    HashRecord *new = NULL;

    if ((!val) ||
        (HASH_KEY_LEN - 1) < strlen(key))
    {
        return NULL;
    }

    new = calloc(1, sizeof(HashRecord));

    if (NULL != new)
    {
        new->value = calloc(1, val_len);
        if (new->value)
        {
            memcpy(&(new->key), key, strlen(key));
            memcpy(new->value, val, val_len);
            printf("New value: %p\n", new->value);
        }
        else
        {
            free(new);
            new = NULL;
        }
    }

    return new;
}


/*******************************************************************************
    ht_destroy_rec
*//**
    @brief  Destroys a hash record
    @param  **rec   Records to be destroyed
*******************************************************************************/
void
ht_destroy_rec(HashRecord **rec)
{
    if (NULL != rec)
    {
        memset((*rec)->value, 0, (*rec)->val_len);
        free((*rec)->value);
        (*rec)->value = NULL;
        memset(*rec, 0, sizeof(**rec));
        free(*rec);
        *rec = NULL;
    }
}


/*******************************************************************************
    ht_init
*//**
    @brief  Creates and initializes a hash table capable of storing M records
    @param  M   Number of records expected to be stored

    Utilizes separate chaining for storing records.

    @return Hash table
    @retval NULL    Unable to create a hash table
*******************************************************************************/
HashTable *
ht_create(size_t M)
{
    HashTable *table = NULL;

    table = calloc(1, sizeof(*table));

    if (NULL == table)
    {
        return NULL;
    }

    /* Don't allocate tiny tables, prime M is preferred */
    M = (M < 100) ? tableSizes[0] : M;

    /* Expect chains to contain about HASH_CHAIN_LEN records a piece */
    table->chainCount = M / HASH_CHAIN_LEN;
    table->chains = calloc(table->chainCount, sizeof(HashChain));

    if (NULL == table->chains)
    {
        free(table);
        table = NULL;
        return NULL;
    }

    table->recLimit = M;

    return table;
}


/*******************************************************************************
    ht_destroy
*//**
    @brief  Destroys a hash table and all elements within it
    @param  **table Hash table to be destroyed
*******************************************************************************/
void
ht_destroy(HashTable **table)
{
    size_t i = 0;
    HashRecord *rec = NULL;
    HashRecord *save = NULL;

    if ((NULL != table) &&
        (NULL != *table))
    {
        for (i = 0; i < (*table)->chainCount; i++)
        {
            dll_for_each(&((*table)->chains[i]), rec, HashRecord *, link, save)
            {
                dll_remove(&(rec->link));
                free(rec);
                rec = NULL;
            }
        }

        free((*table)->chains);
        (*table)->chains = NULL;

        free(*table);
        *table = NULL;
    }
}


/*******************************************************************************
    ht_grow
*//**
    @brief  Enlarges a hash table to accomodate more records
    @param  **table Table to enlarge

    The caller should save a copy of the passed in pointer before assigning the
    return value. This works similarly to realloc().

    @return A newly allocated table with original elements already inserted
    @retval NULL    Table did not exist or could not grow the list
*******************************************************************************/
static HashTable *
ht_grow(HashTable **table)
{
    size_t newCount = 0;
    size_t i = 0;
    HashTable *newTable = NULL;
    HashRecord *rec = NULL;
    HashRecord *save = NULL;

    if ((NULL == table) ||
        (NULL == *table))
    {
        return NULL;
    }

    for (i = 0; i < sizeof(tableSizes)/sizeof(tableSizes[0]); i++)
    {
        if (tableSizes[i] > (*table)->recLimit)
        {
            newCount = tableSizes[i];
            break;
        }
    }

    if (0 != newCount)
    {
        newTable = ht_create(newCount);

        if (NULL != newTable)
        {
            for (i = 0; i < (*table)->chainCount; i++)
            {
                dll_for_each(&((*table)->chains[i]),
                             rec,
                             HashRecord *,
                             link,
                             save)
                {
                    /* Hrm. This potentially puts us in a finite loop */
                    ht_add(&newTable, rec);
                }
            }

            ht_destroy(table);
        }
    }

    return newTable;
}


/*******************************************************************************
    ht_hash
*//**
    @brief  Hashes the record value and stores the result in the record key
    @param  *table  Table to which the key will belong
    @param  *key    Key to be hashed

    @note   This is from program 14.2 "Algorithms in C, 3rd Edition" by Robert
            Sedgewick

    @return Chain index where the entry can be found/stored
    @return -1  Item could not be hashed
*******************************************************************************/
int
ht_hash(HashTable *table, HashKey key)
{
    int h = -1;
    int a = 31415;
    int b = 27183;
    char *keyPtr = key;

    if ((NULL != table) &&
        (NULL != key))
    {
        for (h = 0;
             *keyPtr != '\0';
             keyPtr++, a = (a * b) % (table->chainCount - 1))
        {
            h = ((a * h) + (*keyPtr)) % table->chainCount;
        }
    }

    return h;
}


/*******************************************************************************
    ht_add
*//**
    @brief  Adds a new record to a hash table
    @param  **table Table to have a new record added
    @param  *rec    New record being added

    On success, the passed rec pointer is no longer usable by the caller.

    @return Modified table
    @retval NULL    Table did not exist
*******************************************************************************/
HashTable *
ht_add(HashTable **table, HashRecord *rec)
{
    int hash = 0;
    HashTable *grown = NULL;

    if ((NULL == table) ||
        (NULL == *table) ||
        (NULL == rec))
    {
        return NULL;
    }

    if (NULL != ht_search(*table, rec->key))
    {
        free(rec);
        rec = NULL;
        return *table;
    }

    if ((*table)->recCount == (*table)->recLimit)
    {
        grown = ht_grow(table);

        if (*table == grown)
        {
            return *table;
        }

        *table = grown;
    }

    hash = ht_hash((*table), rec->key);
    dll_insert_back(&((*table)->chains[hash]), &(rec->link));
    ((*table)->recCount)++;

    return *table;
}

/*******************************************************************************
    ht_search
*//**
    @brief  Finds a record with a given key
    @param  *table  Table to be searched
    @param  key     Key to be found

    @return Pointer to a record with the given key
    @retval NULL    No record found with the given key
*******************************************************************************/
HashRecord *
ht_search(HashTable *table, HashKey key)
{
    int hash = 0;
    HashRecord *rec = NULL;
    HashRecord *save = NULL;

    if (NULL != table)
    {
        hash = ht_hash(table, key);

        if (0 <= hash)
        {
            dll_for_each(&(table->chains[hash]), rec, HashRecord *, link, save)
            {
                if (0 == strcmp(key, rec->key))
                {
                    break;
                }
            }
        }
    }

    return rec;
}


/*******************************************************************************
    ht_remove
*//**
    @brief  Removes the given record from the hash table
    @param  *table  Table from which the record will be removed
    @param  *rec    Record to be removed

    @return Modified hash table
    @retval NULL    Table did not exist
*******************************************************************************/
HashTable *
ht_remove(HashTable *table, HashRecord *rec)
{
    if ((NULL != table) &&
        (NULL != rec))
    {
        dll_remove(&(rec->link));
        (table->recCount)--;
    }

    return table;
}


/*******************************************************************************
    ht_print
*//**
    @brief  Display key-value pairs in the hash table
    @param  *table  Hash table to be printed
    @param  *fmt    Format string for pair, only two '%s' specifiers are allowed
*******************************************************************************/
void
ht_print(HashTable *table, char *fmt)
{
    size_t i = 0;
    HashRecord *rec = NULL;
    HashRecord *save = NULL;

    if ((NULL != table) &&
        (NULL != fmt))
    {
        for (i = 0; i < table->chainCount; i++)
        {
            dll_for_each(&(table->chains[i]), rec, HashRecord *, link, save)
            {
                printf(fmt, rec->key, rec->value);
            }
        }
    }
}


size_t
ht_get_rec_count(HashTable *table)
{
    size_t count = 0;

    if (NULL != table)
    {
        count = table->recCount;
    }

    return count;
}
