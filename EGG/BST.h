#ifndef BST_H
#define BST_H

class BST{
private:
    struct node{
        int inf;
        node *left;
        node *right;
    };
    node *tree_root = nullptr;
    int height(node *root);
    bool isBalance(node *root, int *h);
    int maxPath(node *root, int *h);
    void print(node *root);
    void clear(node *root);
public:
    bool isEmpty();
    int height();
    bool isBalance();
    int maxPath();
    bool find(int n);
    void insert(int n);
    void remove(int n);
    void clear();
    void print();
    friend void divide(BST *src, BST *subtree1, BST *subtree2, int n);
};


#endif
