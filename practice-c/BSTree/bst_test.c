// bst_test.c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bstree.h"
#include "bst_test.h"

void test_create_root_ptr() {
    BstNode **root_ptr = Create_root_ptr(42);
    assert(root_ptr != NULL);
    assert(*root_ptr != NULL);
    assert((*root_ptr)->data == 42);
    assert((*root_ptr)->left == NULL);
    assert((*root_ptr)->right == NULL);
    assert((*root_ptr)->parent == NULL);
    printf("test_create_root_ptr passed\n");

    Free_BST(root_ptr);
    free(root_ptr);
}

void test_get_new_node() {
    BstNode *node = Get_new_node(99);
    assert(node != NULL);
    assert(node->data == 99);
    assert(node->left == NULL);
    assert(node->right == NULL);
    assert(node->parent == NULL);
    printf("test_get_new_node passed\n");

    free(node);
}

void test_insert() {
    BstNode **root_ptr = Create_root_ptr(50);
    Insert(root_ptr, 30);
    Insert(root_ptr, 70);
    Insert(root_ptr, 60);

    assert((*root_ptr)->data == 50);
    assert((*root_ptr)->left->data == 30);
    assert((*root_ptr)->right->data == 70);
    assert((*root_ptr)->right->left->data == 60);
    printf("test_Insert passed\n");

    // Freeing is skipped here but should be added for a full test suite
    Free_BST(root_ptr);
    free(root_ptr);
}

void test_search() {
    BstNode **root_ptr = Create_root_ptr(10);
    Insert(root_ptr, 5);
    Insert(root_ptr, 15);

    assert(Search(*root_ptr, 10, NULL) == true);
    assert(Search(*root_ptr, 5, NULL) == true);
    assert(Search(*root_ptr, 15, NULL) == true);
    assert(Search(*root_ptr, 99, NULL) == false);
    printf("test_search passed\n");

    Free_BST(root_ptr);
    free(root_ptr);
}

void test_successor_with_right_subtree() {
    BstNode **root_ptr = Create_root_ptr(20);
    Insert(root_ptr, 10);
    Insert(root_ptr, 30);
    Insert(root_ptr, 25);
    Insert(root_ptr, 35);

    BstNode *succ = Successor(*root_ptr, 20);
    assert(succ != NULL);
    assert(succ->data == 25);
    printf("test_successor_with_right_subtree passed\n");

    Free_BST(root_ptr);
    free(root_ptr);
}

void test_successor_no_right_subtree() {
    BstNode **root_ptr = Create_root_ptr(20);
    Insert(root_ptr, 10);
    Insert(root_ptr, 5);
    Insert(root_ptr, 15);
    Insert(root_ptr, 12);
    Insert(root_ptr, 22);

    BstNode *succ = Successor(*root_ptr, 12);
    assert(succ != NULL);
    assert(succ->data == 15);
    printf("test_successor_no_right_subtree passed\n");

    Free_BST(root_ptr);
    free(root_ptr);
}

void test_successor_no_successor() {
    BstNode **root_ptr = Create_root_ptr(20);
    Insert(root_ptr, 10);
    Insert(root_ptr, 30);
    Insert(root_ptr, 25);
    Insert(root_ptr, 35);

    BstNode *succ = Successor(*root_ptr, 35);
    assert(succ == NULL);
    printf("test_successor_no_successor passed\n");

    Free_BST(root_ptr);
    free(root_ptr);
}

void test_successor_value_not_found() {
    BstNode **root_ptr = Create_root_ptr(20);
    Insert(root_ptr, 10);
    Insert(root_ptr, 30);

    BstNode *succ = Successor(*root_ptr, 999);  // Not in tree
    assert(succ == NULL);
    printf("test_successor_value_not_found passed\n");

    Free_BST(root_ptr);
    free(root_ptr);
}

void test_insert_after() {
    BstNode **root_ptr = Create_root_ptr(20);
    Insert(root_ptr, 10);
    Insert(root_ptr, 30);

    // Insert after 10 — 10 has no right child
    Insert_after(*root_ptr, 10, 15);
    assert((*root_ptr)->left->right != NULL);
    assert((*root_ptr)->left->right->data == 15);
    assert((*root_ptr)->left->right->parent == (*root_ptr)->left);

    // Insert after 10 again — 10 now has a right child, so this inserts after its successor
    Insert_after(*root_ptr, 10, 17);
    BstNode *fifteen = (*root_ptr)->left->right;
    assert(fifteen->right != NULL);
    assert(fifteen->right->data == 17);
    assert(fifteen->right->parent == fifteen);

    // Try Inserting after a non-existent node (should print an error, but not crash)
    Insert_after(*root_ptr, 999, 50);

    printf("test_Insert_after passed\n");

    Free_BST(root_ptr);
    free(root_ptr);
}

void test_predecessor() {
    BstNode **root_ptr = Create_root_ptr(20);
    Insert(root_ptr, 10);
    Insert(root_ptr, 30);
    Insert(root_ptr, 5);
    Insert(root_ptr, 15);
    Insert(root_ptr, 12);
    Insert(root_ptr, 17);

    // Test predecessor with left subtree
    BstNode *pred = Predecessor(*root_ptr, 15);
    assert(pred != NULL);
    assert(pred->data == 12);

    // Test predecessor without left subtree
    pred = Predecessor(*root_ptr, 12);
    assert(pred != NULL);
    assert(pred->data == 10);

    // Test root predecessor
    pred = Predecessor(*root_ptr, 20);
    assert(pred != NULL);
    assert(pred->data == 17);

    // Test no predecessor (smallest element)
    pred = Predecessor(*root_ptr, 5);
    assert(pred == NULL);

    // Test value not in tree
    pred = Predecessor(*root_ptr, 99);
    assert(pred == NULL);

    printf("test_predecessor passed\n");

    Free_BST(root_ptr);
    free(root_ptr);
}

void test_bst_delete() {
    BstNode **root_ptr = Create_root_ptr(50);
    Insert(root_ptr, 30);
    Insert(root_ptr, 70);
    Insert(root_ptr, 20);
    Insert(root_ptr, 40);
    Insert(root_ptr, 60);
    Insert(root_ptr, 80);

    // Case 1: Delete a leaf (20)
    Bst_delete(*root_ptr, 20);
    BstNode *res = NULL;
    assert(Search(*root_ptr, 20, &res) == false);

    // Case 2: Delete node with one child (30 has only 40 now)
    Bst_delete(*root_ptr, 30);
    assert(Search(*root_ptr, 30, &res) == false);
    assert((*root_ptr)->left->data == 40);

    // Case 3: Delete node with two children (70)
    Bst_delete(*root_ptr, 70);
    assert(Search(*root_ptr, 70, &res) == false);
    assert((*root_ptr)->right->data != 70); // likely 80 or 60

    // Delete root node (50)
    Bst_delete(*root_ptr, 50);
    assert(Search(*root_ptr, 50, &res) == false);

    printf("test_bst_delete passed\n");

    Free_BST(root_ptr);
    free(root_ptr);
}


void run_all_tests() {
    test_create_root_ptr();
    test_get_new_node();
    test_insert();
    test_successor_with_right_subtree();
    test_successor_no_right_subtree();
    test_successor_no_successor();
    test_successor_value_not_found();
    test_search();
    test_insert_after();
    test_predecessor();
    test_bst_delete();
}
