#include "hash_table.h"
#include <assert.h>
#include <string.h>

hash_table *create_table(size_t size) {
	// Create the map
	hash_table *fresh = (hash_table*)malloc(sizeof(hash_table));
	assert(fresh != 0);

	// Create room for all the values
	fresh->data = malloc(sizeof(*fresh->data) * size);
	//fresh->data = (key_value**)malloc(sizeof(key_value*)*size);
	assert(fresh->data != 0);

	// Initialize all the values
	for (size_t i = 0; i < size; i++) {
		fresh->data[i] = NULL;
	}
	fresh->size = size;
	
	return fresh;
}

void destroy_table(hash_table *hash_table) {

	for (size_t i = 0; i < hash_table->size; i++) {
		key_value *kv= hash_table->data[i];
		while(kv) {
			key_value *next = kv->next;
			free(kv->key);
			free(kv->value);
			free(kv);
			kv = next;
		}
	}

	free(hash_table->data);
	free(hash_table);
}

int hash(const char *key, const size_t size) {
	int hash = 0;

	for (size_t i = 0; key[i] != '\0'; i++) {
		hash = hash * 31 + key[i];
	}
	return hash % size;
}

void add(hash_table *table, const char *key, const key_value *object) {
	int index = hash(key, table->size);

	key_value *kv = get(table, key);
	if (kv != NULL) {
		free(kv->value);
		kv->value = strdup(object->value);
	}

	kv = malloc(sizeof(key_value));
	kv->key = strdup(object->key);
	kv->value = strdup(object->value);
	kv->next = table->data[index];
	table->data[index] = kv;
}

key_value* get(const hash_table* table, const char* key) {
	int index = hash(key, table->size);

	key_value *kv = table->data[index];
	while (kv) {
		if (strcmp(kv->key, key) == 0) {
			return kv;
		}
		kv = kv->next;
	}

	return NULL;
}

bool exists(const hash_table* table, const char* key) {
	key_value *kv = get(table, key);
	return kv != NULL;
}

void delete(hash_table *table, const char *key) {
	int index = hash(key, table->size);
	key_value *prev = NULL;

	key_value *kv = table->data[index];
	while (kv) {
		if (strcmp(kv->key, key) == 0) {
			// if its the head
			if (prev == NULL) {
				table->data[index] = kv->next;
			} else {
				prev->next = kv->next;
			}

			free(kv->key);
			free(kv->value);
			free(kv);
			return;
		}
		prev = kv;
		kv = kv->next;
	}
}

void Print_Debug(hash_table * hash_table) {
	for (size_t i = 0; i < hash_table->size; i++) {
		if (hash_table->data[i] == NULL) {
			printf("%zu:\n", i);
		} else {
			printf("%s: %s\n", hash_table->data[i]->key, hash_table->data[i]->value);
		}
	}
	printf("===================\n");
}
