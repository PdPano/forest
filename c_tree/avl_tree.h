#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP
#include <stdio.h>
#include <stdlib.h>

struct avl_node
{
    int key,value;
    int height;
    struct avl_node *left, *right;
};

typedef struct avl_node avl_node_t;
int max(int a, int b);

avl_node_t* create_node(int key, int value);
int get_balance(avl_node_t* node);
int height(avl_node_t* node);
void update_height(avl_node_t* node);
avl_node_t* insert_node(avl_node_t* node, int key, int value);
avl_node_t* delete_node(avl_node_t* node, int key);
avl_node_t* left_rotate(avl_node_t* node);
avl_node_t* right_rotate(avl_node_t* node);
avl_node_t* find_node(avl_node_t* node, int key);
avl_node_t* find_min_key(avl_node_t* node);
void print_inorder(avl_node_t* node);
void print_node(avl_node_t* node);
void clear_tree(avl_node_t* node);
#endif
