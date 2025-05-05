#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int value;
	struct node* next;
	struct node* tail;
} node;

node *contructor_queue(int value);
void enqueue(node *queue, int value);
int dequeue(node **queue);
bool empty(node *queue);
void print_queue(node *queue);

int main() {
	node *head = contructor_queue(0);
	enqueue(head, 1);
	enqueue(head, 2);
	enqueue(head, 3);
	enqueue(head, 4);

	print_queue(head);

	int value1 = dequeue(&head);
	printf("The last value dequeued is %d\n", value1);
	int value2 = dequeue(&head);
	printf("The last value dequeued is %d\n", value2);
	int value3 = dequeue(&head);
	printf("The last value dequeued is %d\n", value3);
	int value4 = dequeue(&head);
	printf("The last value dequeued is %d\n", value4);
	int value5 = dequeue(&head);
	printf("The last value dequeued is %d\n", value5);
	int value6 = dequeue(&head);
	printf("The last value dequeued is %d\n", value6);
	print_queue(head);
}

node *contructor_queue(int value) {
	node *new_node = (node *)malloc(sizeof(node));
	if (new_node == NULL) {
		fprintf(stderr, "Malloc didn't work as expected\n");
		exit(1);
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->tail = new_node;
	return new_node;
}
void enqueue(node *queue, int value) {
	node *new_node = (node *)malloc(sizeof(node));
	if (new_node == NULL) {
		fprintf(stderr, "Malloc didn't work as expected\n");
		exit(1);
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->tail = new_node;
	queue->tail->next = new_node;
	queue->tail = new_node;
}

int dequeue(node **queue) {
	if (*queue == NULL) {
		fprintf(stderr, "NO MORE VALUES IN THE QUEUE\n");
		exit(1);
	}
	node *first = *queue;
	*queue = first->next;
	int value = first->value;

	free(first);
	return value;
}

bool empty(node *queue) {
	if (queue != NULL) return false;
	return true;
}

void print_queue(node *queue) {
	while(queue !=NULL) {
		printf("%d -> ", queue->value);
		queue = queue->next;
	}
	printf("NULL\n");
}
