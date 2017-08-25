#include "avl_tree.h"

int max(int a, int b)
{
    return (a > b)? a : b;
}

avl_node_t* create_node(int key,int value)
{
    avl_node_t *node = (avl_node_t*) malloc(sizeof(avl_node_t));
    if(node==NULL)
    {
        printf("Not enough memory!!!!\n");
    }
    else
    {
        node->key = key;
        node->value = value;
        node->left  = NULL;
        node->right = NULL;
        node->height = 1;
    }
    return node;
}

int height(avl_node_t *node)
{
    if(node==NULL)
        return 0;
    return node->height;
}

void update_height(avl_node_t* node)
{
    if(node==NULL)
        return;
    node->height = max(height(node->left),height(node->right))+1;
}

int get_balance(avl_node_t *node)
{
    if(node==NULL)
        return 0;
    return height(node->left)-height(node->right);
}

avl_node_t* insert_node(avl_node_t *node, int key, int value)
{
    /*Find where we should insert the node*/
    if(node==NULL)
        return create_node(key,value);
    if(key < node->key)
    {
        node->left = insert_node(node->left, key, value);
    }
    else if(key > node->key)
    {
        node->right = insert_node(node->right, key, value);
    }
    else
    {
        printf("Cannot insert the same key twice\n");
        return node;
    }
    update_height(node);
    int local_balance = get_balance(node);

    /*
     * If the subtree is not balanced we can be sure there is at least one child
     * And the sign of local_balance tells us which side is certainly occupied
     * This allows us to use the left or the right pointer without checking
     * for NULL
     */
    /* Left Left*/
    if(local_balance > 1 && key < node->left->key)
    {
        return right_rotate(node);
    }
    /* Left Right*/
    if(local_balance > 1 && key > node->left->key)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    /* Right Right*/
    if(local_balance < -1 && key > node->right->key)
    {
        return left_rotate(node);
    }
    /* Right Left */
    if(local_balance < -1 && key < node->right->key)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    /* Subtree is still balanced*/
    return node;
}

/*
 * ASCII art explanation of tree rotations
 *  left tree                 right tree
 *
 *     X                          Y
 *    / \                        / \
 *   Y   A                      B   X
 *  / \                            / \
 * B   grandchild        grandchild    A
 *
 *    >-->-->  right rotation >-->-->
 *    <--<--<  left  rotation <--<--<
 */

avl_node_t* left_rotate(avl_node_t* node)
{
    avl_node_t* child = node->right;
    avl_node_t* grandchild = child->left;

    child->left = node;
    node->right  = grandchild;

    update_height(node);
    update_height(child);

    return child;
}

avl_node_t* right_rotate(avl_node_t* node)
{
    avl_node_t* child = node->left;
    avl_node_t* grandchild = child->right;

    child->right = node;
    node->left  = grandchild;

    update_height(node);
    update_height(child);

    return child;
}

avl_node_t* find_node(avl_node_t* node, int key)
{
    avl_node_t* ret_node;
    if(node==NULL)
    {
        printf("Key %d not found\n", key);
        ret_node=NULL;
    }
    else
    {
        if( key < node->key)
            ret_node = find_node(node->left, key);
        else if( key > node->key)
            ret_node = find_node(node->right, key);
    }
    return ret_node;
}
