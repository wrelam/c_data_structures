/***************************************************************************//**
    @file   hash.h

    @brief  Interface to a hash table implementation for string values
*******************************************************************************/
#ifndef HASH_H
#define HASH_H

#include <stddef.h>
#include <stdio.h>

#include "list_doubly.h"

#define HASH_KEY_LEN    (FILENAME_MAX + 1)

typedef char HashKey[HASH_KEY_LEN];

typedef struct HashRecord
{
    dll_node link;
    HashKey key;
    void *value;
    size_t val_len;
} HashRecord;

typedef struct HashTable HashTable;

HashTable *
ht_create(size_t M);

void
ht_destroy(HashTable **table);

HashRecord *
ht_create_rec(HashKey key, void *val, size_t val_len);

void
ht_destroy_rec(HashRecord **rec);

HashTable *
ht_add(HashTable **table, HashRecord *rec);

HashRecord *
ht_search(HashTable *table, HashKey key);

HashTable *
ht_remove(HashTable *table, HashRecord *rec);

int
ht_hash(HashTable *table, HashKey key);

void
ht_print(HashTable *table, char *fmt);

size_t
ht_get_rec_count(HashTable *table);

#endif /* HASH_H */

