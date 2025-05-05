#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int value;
	struct node *next;
} node;

node *create_node(int value) {
	node *new_node = (node *)malloc(sizeof(node));
	if (!new_node) {
		fprintf(stderr, "Malloc didn't work as planned\n");
		exit(1);
	}

	new_node->value = value;
	new_node->next = NULL;
	return new_node;
}

size_t size(node *list) {
	size_t len = 0;
	for (node *act = list; act != NULL; act = act->next) {
		len += 1;
	}
	return len;
};

bool empty(node *list) {
	if (list != NULL) {
		return false;
	}
	return true;
}

// does not account for values over the limit
int value_at(node *list, size_t idx) {
	size_t i = 0;
	node *current = list;
	while (current != NULL && i < idx) {
		current = current->next;
		i++;
	}
	return current->value;
}

node *push_front(node *list, int value) {
	node *new_node = (node *)malloc(sizeof(node));
	if (!new_node) {
		fprintf(stderr, "Malloc didn't work as planned\n");
		exit(1);
	}
	new_node->value = value;
	new_node->next = list;

	return new_node;
}

int pop_front(node **plist) {
	int val = (*plist)->value;
	node *current = *plist;
	*plist = (*plist)->next;
	free(current);
	return val;
}

void free_list(node *list) {

	while(list != NULL) {
		node *tmp = list->next;
		free(list);
		list = tmp;
	}
}

void print_list(node *list) {
	node *current = list;
	while(current != NULL) {
		printf("%d -> ", current->value);
		current = current->next;
	}
	printf("NULL\n");
}




int main() {
	node *head = NULL, *current = NULL;

	// Create linked list with length 5
	for (int i = 1; i <= 5; i++) {
		node *new_node = create_node(i);
		if (head == NULL) {
			head = new_node;
			current = head;
		} else {
			current->next = new_node;
			current = new_node;
		}
	}
	head = push_front(head, 0);
	int value = pop_front(&head);
	printf("popped is %d\n", value);
	printf("size %zu\n", size(head));

	// Print the linked list
	print_list(head);

	// Free allocated memory
	free_list(head);

	return 0;
}
