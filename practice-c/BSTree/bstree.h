#include <stdbool.h>

#ifndef bstree_project
#define bstree_project
// This
typedef struct BSTNode {
	int data;
	struct BSTNode *right;
	struct BSTNode *left;
	struct BSTNode *parent;
} BstNode;

BstNode **Create_root_ptr(int value);
BstNode *Get_new_node(int value);
void Insert(BstNode** root_ptr, int data);
bool Search(BstNode* root, int data, BstNode **result);
void Free_BST(BstNode **root_ptr);
BstNode *Successor(BstNode *root, int data);
BstNode *Predecessor(BstNode *root, int data);
void Insert_after(BstNode *root, int prev, int value);
void Bst_delete(BstNode *root, int data);
int FindMin(BstNode *root);
int FindMax(BstNode *root);

#endif //bstree_project
