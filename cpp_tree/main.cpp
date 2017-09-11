#include "avl_tree.hpp"
#include <iostream>

int main()
{
    Tree<int,int> t;
    t.insert_node(5,1);
    t.insert_node(2,2);
    t.insert_node(8,3);
    t.insert_node(1,4);

    std::cout<<"Tree<int, int>"<<std::endl;
    t.print_inorder();
    t.clear_tree();
    std::cout<<"Cleaer Tree<int, int>"<<std::endl;
    t.print_inorder();

    Tree<int, std::string> s;
    s.insert_node(5,"a");
    s.insert_node(2,"b");
    s.insert_node(8,"c");
    s.insert_node(1,"d");

    std::cout<<"Tree<int, std::string>"<<std::endl;
    s.print_inorder();
}
