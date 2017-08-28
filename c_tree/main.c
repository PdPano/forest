#include <stdio.h>
#include "avl_tree.h"

int main(int argc, char *argv[])
{
    int i;
    avl_node_t* tree=NULL;
    avl_node_t* aux;
    for(i=0;i<10;i++)
    {
        tree = insert_node(tree,i,2*i);
    }
    print_inorder(tree);
    printf("Node is in tree ###############\n");
    aux = find_node(tree,5);
    print_node(aux);
    tree = delete_node(tree,5);
    tree = delete_node(tree,7);
    printf("Node is NOT in tree ###############\n");
    aux = find_node(tree,5);
    print_node(aux);
    clear_tree(tree);
}
