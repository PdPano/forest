#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <iostream>
#include <stack>
#include <memory>

template<typename K, typename V>
struct node
{
    K k;
    V v;
    std::shared_ptr< node<K,V> > left,right;

    int height;

    node(K k_in, V v_in):k(k_in),v(v_in),height(0){}
};

template<typename K, typename V>
using node_sp = std::shared_ptr<node<K,V> >;

template<typename K, typename V>
std::ostream& operator<<(std::ostream& stream, const node<K,V>& n)
{
    stream << "("<<n.k <<", "<<n.v<<")";
}

template<typename K, typename V>
class Tree
{
    public:
        void insert_node(K k, V v);
        node_sp<K,V> delete_node(K k);
        node_sp<K,V> find_node(K k);
        void clear_tree(void){root = nullptr;}
        void print_inorder(void);

    private:
        node_sp<K,V> root;
        std::stack<node_sp<K,V> > stack_to_node(K k);
        int height(node_sp<K,V> curr);
        void update_height(node_sp<K,V> curr);
        int get_balance(node_sp<K,V> curr);
        void print_inorder(node_sp<K,V> curr);
        void print_node(node_sp<K,V> curr);
};

template<typename K, typename V>
std::stack<node_sp<K,V> > Tree<K,V>::stack_to_node(K k)
{
    node_sp<K,V> curr = root;
    std::stack<node_sp<K,V> > path;
    path.push(curr);
    while(curr!=nullptr)
    {
        if(curr->k == k)
            break;
        else if(k < curr->k ){
            curr = curr->left;
            path.push(curr);
        }
        else if(k > curr->k){
            curr = curr->right;
            path.push(curr);
        }
    }
    return path;
}

template<typename K, typename V>
void Tree<K,V>::print_node(node_sp<K,V> curr)
{
    if( curr != nullptr)
        std::cout<<"node ("
                 <<curr->k
                 <<", "
                 <<curr->v
                 <<")"
                 <<std::endl;
}

template<typename K, typename V>
int Tree<K,V>::height(node_sp<K,V> curr)
{
    if(curr == nullptr)
        return 0;
    else
        return curr->height;
}

template<typename K, typename V>
void update_height(node_sp<K,V> curr)
{
    if(curr==nullptr)
        return;
    curr->height = std::max(height(curr->left),height(curr->right))+1;
}

template<typename K, typename V>
int get_balance(node_sp<K,V> curr)
{
    if(curr==nullptr)
        return 0;
    return height(curr->left)-height(curr->right);
}

template<typename K, typename V>
void Tree<K,V>::insert_node(K k, V v)
{
    std::stack< node_sp<K,V> > path = stack_to_node(k);
    node_sp<K,V> curr = path.top();
    if(curr!=nullptr)
    {
        std::cout<<"Cannot insert same key ("<< k <<") twice!" << std::endl;
        return;
    }
    path.pop();
    node_sp<K,V> to_insert(new node<K,V>(k,v));
    if(path.empty())//only if root is nullptr
    {
        root = to_insert;
        return;
    }
    curr = path.top();
    if(k < curr->k)
    {
        curr->left = to_insert;
    }
    else
    {
        curr->right = to_insert;
    }
}

template<typename K, typename V>
node_sp<K,V> Tree<K,V>::delete_node(K k)
{
}

template<typename K, typename V>
node_sp<K,V> Tree<K,V>::find_node(K k)
{
    node_sp<K,V> curr = root;
    while(curr!=nullptr)
    {
        if(k == curr->k)
            break;
        if(k < curr->k)
            curr = curr->left;
        else if(k > curr->k)
            curr = curr->right;
    }
    return curr;
}

template<typename K, typename V>
void Tree<K,V>::print_inorder(void)
{
    print_inorder(root);
}

template<typename K, typename V>
void Tree<K,V>::print_inorder(node_sp<K,V> curr)
{
    if(curr!=nullptr)
    {
        print_inorder(curr->left);
        print_node(curr);
        print_inorder(curr->right);
    }
}
#endif /* AVL_TREE_HPP */
