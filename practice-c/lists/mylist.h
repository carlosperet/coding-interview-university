#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef mylist
typedef struct node {
	int value;
	struct node * next;
} node;

node *node_constructor(int value);

void print_list(node *list);

void free_list(node *list);

size_t size_list(node *list);

bool empty(node *list);

int value_at(node *list, size_t index);

void push_front(node **list, int value);

int pop_front(node **list);

void node_push_back(node *list, int value);

int node_pop_back(node *list);

int front(node *list);

int back(node *list);

void insert(node **list, size_t index, int value);

void erase(node **list, size_t index);

int value_n_from_end(node *list, size_t index);

void reverse(node **list);

void remove_value(node *list, int value);
#endif
