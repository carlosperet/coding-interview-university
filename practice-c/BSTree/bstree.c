#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"


BstNode **Create_root_ptr(int value) {
    BstNode **root_ptr = (BstNode **)malloc(sizeof(BstNode *));
    if (!root_ptr) {
        printf("Error: memory for root pointer could not be allocated\n");
        return NULL;
    }

    *root_ptr = Get_new_node(value);
    if (!*root_ptr) {
        free(root_ptr);  // clean up if node allocation fails
        return NULL;
    }

    return root_ptr;
}

BstNode *Get_new_node(int value) {
	BstNode *new_node = (BstNode *)malloc(sizeof(BstNode));
	if (!new_node) {
		printf("Error: memory for node of value %d could not be allocated\n", value);
		return NULL;
	}

	new_node->data = value;
	new_node->right = NULL;
	new_node->left = NULL;
	new_node->parent = NULL;
	return new_node;
}

void Insert(BstNode** root_ptr, int data) {
	// Check if pointer to pointer exists
	if (root_ptr == NULL) {
		printf("Error: pointer to root is NULL\n");
		return;
	}

	// This should not happen if they used CreateRootPtr
	if (*root_ptr == NULL) {
		*root_ptr = Get_new_node(data);
		return;
	}

	// Create new node
	BstNode *new_node = Get_new_node(data);
	if (!new_node) {
		printf("Error: could not allocate new node\n");
		return;
	}

	BstNode *cp_root = *root_ptr;
	BstNode *prev_root = NULL;
	bool is_left = false;

	while(cp_root) {
		prev_root = cp_root;
		if (cp_root->data >= data) {
			cp_root = cp_root->left;
			is_left = true;
		} else if(cp_root->data < data) {
			cp_root = cp_root->right;
			is_left = false;
		}
	}

	new_node->parent = prev_root;
	if (is_left) {
		prev_root->left = new_node;
	} else {
		prev_root->right = new_node;
	}
}

bool Search(BstNode* root, int data, BstNode **result) {
	if (!root) {
		if (result != NULL) {
			*result = NULL;
		}
		return false;
	}
	if (root->data == data) {
		if (result != NULL) {
			*result = root;
		}
		return true;
	}
	
	if (root->data >= data) {
		return Search(root->left, data, result);
	}
	else {
		return Search(root->right, data, result);
	}
}

void Free_BST(BstNode **root_ptr) {
	if (root_ptr == NULL || *root_ptr == NULL) return;

	BstNode *root = *root_ptr;

	
	if (root->left != NULL) {
		Free_BST(&root->left);
	}
	if (root->right != NULL) {
		Free_BST(&root->right);
	}
	
	free(root);
	*root_ptr = NULL;
}

BstNode *Successor(BstNode *root, int data) {
	BstNode *target = NULL;
	bool exists = Search(root, data, &target);

	if (!exists) return NULL;

	if (target->right) {
		// Search for first
		BstNode *curr = target->right;
		while (curr->left) {
			curr = curr->left;
		}
		return curr;
	} else {
		// Walk up the tree until go up a left branch
		BstNode *curr = target;
		BstNode *ancestor = curr->parent;
		while (ancestor && ancestor->right == curr) {
			curr = ancestor;
			ancestor = ancestor->parent;
		}
		return ancestor;
	}
}

BstNode *Predecessor(BstNode *root, int data) {
	BstNode *target = NULL;
	bool exists = Search(root, data, &target);

	if (!exists) return NULL;

	if (target->left) {
		// Search for first
		BstNode *curr = target->left;
		while (curr->right) {
			curr = curr->right;
		}
		return curr;
	} else {
		// Walk up the tree until go up a left branch
		BstNode *curr = target;
		BstNode *ancestor = curr->parent;
		while (ancestor && ancestor->left == curr) {
			curr = ancestor;
			ancestor = ancestor->parent;
		}
		return ancestor;
	}
}

void Insert_after(BstNode *root, int prev, int value) {
	BstNode *prevNode = NULL;
	bool exists = Search(root, prev, &prevNode);
	if (!exists) {
		printf("Error: the value %d does not exist on Tree\n", prev);
		return;
	}

	BstNode *newNode = Get_new_node(value);

	if (!prevNode->right) {
		prevNode->right = newNode;
		newNode->parent = prevNode;
		return;
	}

	BstNode *succ = Successor(root, prev);
	succ->right = newNode;
	newNode->parent = succ;
}

void Bst_delete(BstNode *root, int data) {
	BstNode *result = NULL;
	bool exists = Search(root, data, &result);
	if (!exists) return;
	

	// Easiest case, we are on a leaf
	if (result->left == NULL && result->right == NULL) {
		if ((result->parent)->right == result) {
			result->parent->right = NULL;
		} else {
			result->parent->left = NULL;
		}
		free(result);
		return;
	}
	if (result->left != NULL) {
		BstNode *predecessor = Predecessor(root, data);
		result->data = predecessor->data;
		predecessor->data = data;
		Bst_delete(root, data);
	} else if (result->right != NULL) {
		BstNode *succ = Successor(root, data);
		result->data = succ->data;
		succ->data = data;
		Bst_delete(root, data);
	}
}

int Get_min(BstNode *root) {
	if (!root) {
		return INT_MIN;
	}

	while(root->left) {
		root = root->left;
	}
	return root->data;
}
int Get_max(BstNode *root) {
	if (!root) {
		return INT_MIN;
	}

	while(root->right) {
		root = root->right;
	}
	return root->data;
}

int Find_height(BstNode *root) {
	if (!root) {
		return -1;
	}

	int leftHeight = Find_height(root->left);
	int rightHeight = Find_height(root->right);

	return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

/* 
* 0 is Preorder
* 1 is 
*/
void Depth_BS(BstNode *root, int type, int *result) {
	if (type < 0 || type > 2) return;
	if (type == 0) {
		result[0] = root->data;
	}
}
