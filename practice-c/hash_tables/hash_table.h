#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#ifndef PROJECT_HASH_TABLE_H
#define PROJECT_HASH_TABLE_H

// the keyvalues are a linked list once the slot has already been used before
typedef struct KeyValue {
	char *key;
	char *value;
	struct KeyValue *next;
} key_value;

// the hashmap contains a pointer to the pointer that points to the first key_value element
typedef struct HashTable {
	key_value **data;
	size_t size;
} hash_table;

// Create the table by passing the size of it
hash_table *create_table(size_t size);
// Free the memory of the table by passing its reference
void destroy_table(hash_table *hash_table);
// Universal string hashing algorithm
int hash(const char *key, const size_t size);
// passing the key and the value, create or update the table
void add(hash_table *hash_table, const char *key, const key_value *object);
// Get the first value of the key
key_value* get(const hash_table* table, const char* key);
// Returns true if the given key exists in the table
bool exists(const hash_table* table, const char* key);
void Print_Debug(hash_table * hash_table);
// Removes the value associated with key from table
void delete(hash_table *table, const char *key);


#endif // PROJECT_HASH_TABLE_H
