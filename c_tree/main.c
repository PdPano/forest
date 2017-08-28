#include <stdio.h>
#include "avl_tree.h"

int main(int argc, char *argv[])
{
    avl_node_t* tree=NULL;
    tree = insert_node(tree,0,0);
    tree = insert_node(tree,4,4);
    tree = insert_node(tree,2,0);
    tree = insert_node(tree,3,1);
    print_inorder(tree);
    delete_node(tree,4);
    print_inorder(tree);
    clear_tree(tree);
}
