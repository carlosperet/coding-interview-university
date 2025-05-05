#include "mylist.h"

int main() {
	node *head = node_constructor(5);
	for (int i = 4; i > 0; i--) {
		push_front(&head, i);
	}

	push_front(&head, 0);
	node_push_back(head, 6);
	insert(&head, 0, -1);

	insert(&head, 8, 7);

	insert(&head, 2, 100);

	erase(&head, 2);

	printf("The third value from the end of the list is: %d\n", value_n_from_end(head, 3));

	printf("The size of the list is: %zu\n", size_list(head));
	reverse(&head);
	print_list(head);

	free_list(head);
}

node *node_constructor(int value){
	node *list = (node *)malloc(sizeof(node));
	if (list == NULL) {
		fprintf(stderr, "Malloc constructor didn't go as planned");
		exit(1);
	}

	list->value = value;
	list->next = NULL;
	return list;
}

void push_front(node **list, int value) {
	node *new_node= (node *)malloc(sizeof(node));

	if (new_node == NULL) {
		fprintf(stderr, "Malloc newList didn't go as planned");
		exit(1);
	}

	new_node->value = value;
	new_node->next = *list;

	*list = new_node;
}

void print_list(node *list) {
	node *curr = list;

	while (curr != NULL) {
		printf("%d -> ", curr->value);
		curr = curr->next;
	}
	printf("NULL\n");
}

void free_list(node *list) {
	while (list != NULL) {
		node *current = list->next;
		free(list);
		list = current;
	}
}


size_t size_list(node *list) {
	size_t len = 0;
	node *curr = list;

	while(curr != NULL) {
		len += 1;
		curr = curr->next;
	}

	return len;
}

bool empty(node *list) {
	if (list != NULL) return false;

	return true;
}

int value_at(node *list, size_t idx) {
	size_t i_curr = 0;
	node *current = list;
	while (current != NULL && i_curr <= idx) {
		
		if (i_curr == idx) return current->value;

		current = current->next;
		i_curr++;
	}

	fprintf(stderr, "Index greater that list's length\n");
	exit(1);
}

int pop_front(node **list) {
	node *old_ini = *list;
	int value = old_ini->value;
	*list = old_ini->next;
	free(old_ini);
	return value;
}

void node_push_back(node *list, int value) {
	node *curr = list;
	node *new_node = (node *)malloc(sizeof(node));
	if (new_node == NULL) {
		fprintf(stderr, "Malloc push_back didn't go as planned");
		exit(1);
	}
	while(curr->next != NULL) {
		curr = curr->next;
	}

	curr->next = new_node;
	new_node->value = value;
	new_node->next = NULL;
}

int node_pop_back(node *list) {
	node *curr_1 = list;
	node *curr = curr_1->next;
	int value = 0;


	while(curr->next != NULL) {
		curr_1 = curr;
		curr = curr->next;
	}

	curr_1->next = NULL;
	value = curr->value;
	free(curr);
	
	return value;
}

int front(node *list) {
	if (list == NULL) {
		fprintf(stderr, "The list was not initialized");
		exit(1);
	}
	return list->value;
}

int back(node *list) {
	if (list == NULL) {
		fprintf(stderr, "The list was not initialized");
		exit(1);
	}

	node *curr = list;
	while (curr->next != NULL) curr = curr->next;

	return curr->value;
}

void insert(node **list, size_t index, int value) {

	if (*list == NULL && index > 0) {
		fprintf(stderr, "Cannot insert at index %zu in an empty list\n", index);
		exit(1);
	}

	// Case: Insert at front
	if (index == 0) {
		push_front(list, value);
		return;
	}


	node *curr_1 = *list;
	node *curr = curr_1->next;
	size_t i_curr = 1;

	while (curr != NULL && i_curr < index) {
		curr_1 = curr;
		curr = curr->next;
		i_curr++;
	}

	// 3 casos 
	// 1. que estoy en el ultimo y no he llegado hasta el fin
	// 2. que estoy en el ultimo y que quiero añadir un ultimo
	// 3. que estoy en el medio
	
	if(curr == NULL && i_curr < index) {
		fprintf(stderr, "Trying to add a value beyond the allowed range\n");
		exit(1);
	}

	node *new_node = (node *)malloc(sizeof(node));
	if (new_node == NULL) {
		fprintf(stderr, "Memory allocation insert failed\n");
		exit(1);
	}

	new_node->value = value;
	new_node->next = curr;
	curr_1->next = new_node;
}

void erase(node **list, size_t index) {
	if (*list == NULL) {
		fprintf(stderr, "Cannot erase at index %zu in an empty list\n", index);
		exit(1);
	}
	
	node *curr_1 = *list;
	node *curr = curr_1->next;
	size_t i_curr = 1;

	while (curr != NULL && i_curr < index) {
		curr_1 = curr;
		curr = curr->next;
		i_curr++;
	}

	node *elim_node = curr;
	
	curr = curr->next;

	curr_1->next = curr;
	free(elim_node);
}

int value_n_from_end(node *list, size_t index) {
	size_t last = size_list(list);
	if (last == 0) {
		fprintf(stderr, "List is empty\n");
		exit(1);
	}
	size_t idx = 0;
	node *curr = list;

	// no need to check if in bounce since size_list did it for us
	while(idx < (last - index)) {
		curr = curr->next;
		idx++;
	}
	return curr->value;
};


void reverse(node **list) {
	node *before = NULL;
	node *curr = *list;
	node *next = NULL;
	while(curr != NULL) {
		next = curr->next;
		curr->next = before;
		before = curr;
		curr = next;
	}
	*list = before;
}

void remove_value(node *list, int value) {
	node *next = list->next;
	while(next != NULL && next->value != value) {
		list = next;
		next = next->next;
	}
	if(next == NULL) {
		fprintf(stdout, "The value: %d was NOT found on the list\n", value);
		return;
	}
	list->next = next->next;
	free(next);
}
