#include "BST.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

/* Phuong thuc tinh do cao cua 1 nut */
int BST::height(node* root)
{
    if(root == nullptr)
        return 0;
    return std::max(height(root->left), height(root->right)) + 1;
}

bool BST::isBalance(node *root, int *h)
{
    if(root == nullptr) {
        *h = 0;
        return true;
    }
    int hl = 0, hr = 0;
    bool isBalanceL = isBalance(root->left, &hl);
    bool isBalanceR = isBalance(root->right, &hr);
    *h = std::max(hl, hr) + 1;
    return isBalanceL && isBalanceR && abs(hl - hr)<=1;
}

int BST::maxPath(node *root, int *h)
{
    if(root == nullptr) {
        *h = 0;
        return 0;
    }
    int hl = 0, hr = 0;
    int maxL = maxPath(root->left, &hl);
    int maxR = maxPath(root->right, &hr);
    *h = std::max(hl, hr) + 1;
    return std::max(std::max(maxL, maxR), hl+hr);
}

bool BST::find(int n)
{
    node *cursor = tree_root;
    while(cursor != nullptr) {
        if(cursor->inf == n) return true;
        if(n < cursor->inf) cursor=cursor->left;
        else cursor=cursor->right;
    }
    return false;
}

/* Phuong thuc tra ve do cao cua cay */
int BST::height()
{
    return height(tree_root);
}

bool BST::isBalance()
{
    int h = 0;
    return isBalance(tree_root, &h);
}

bool BST::isEmpty()
{
    return tree_root == nullptr;
}

int BST::maxPath()
{
    int h = 0;
    return maxPath(tree_root, &h);
}

void BST::remove(int n)
{
    node **p_cursor = &tree_root;

    /*Tim dia chi cua node can xoa*/
    while(*p_cursor != nullptr) {
        if(n < (*p_cursor)->inf) {
            p_cursor = &(*p_cursor)->left;
        } else if(n > (*p_cursor)->inf) {
            p_cursor = &(*p_cursor)->right;
        } else break;
    }
    node *cursor = *p_cursor;
    try{
        if(cursor == nullptr)
            throw "Cannot remove";

        if(cursor->left == nullptr && cursor->right == nullptr) *p_cursor=nullptr;
        else if(cursor->left == nullptr) *p_cursor=cursor->right;
        else if(cursor->right == nullptr) *p_cursor = cursor->left;
        else {
            /* Truong hop ca 2 nut con deu khong rong */
            node **tmp = &cursor->right;
            while((*tmp)->left != nullptr) {
                tmp = &(*tmp)->left;
            }

            (*p_cursor)->inf = (*tmp)->inf;
            cursor = *tmp;
            *tmp = (*tmp)->right;
        }

        delete cursor;
    }
    catch(const char *msg) {
        std::cerr << msg << std::endl;
    }
}

void BST::insert(int n)
{
    node **p_cursor = &tree_root;
    try{
        while(*p_cursor != nullptr) {
            if(n < (*p_cursor)->inf) p_cursor=&(*p_cursor)->left;
            else if(n > (*p_cursor)->inf) p_cursor=&(*p_cursor)->right;
            else throw "Duplicate value";
        }

        node *newNode = new node;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->inf = n;
        *p_cursor = newNode;
    } catch (const char*msg) {
        std::cerr << msg << std::endl;
    }
}

void BST::print(node *root)
{
    if(root == nullptr) return;
    print(root->left);
    std::cout << root->inf << " ";
    print(root->right);
}

void BST::print()
{
    print(tree_root);
}

void BST::clear(node *root)
{
    if(root == nullptr)
        return;
    clear(root->left);
    clear(root->right);
    delete root;
}

void BST::clear()
{
    this->clear(tree_root);
    tree_root = nullptr;
}

void divide(BST *src, BST *subtree1, BST *subtree2, int n)
{
    BST::node *cursor = src->tree_root;
    if(cursor->inf == n) {
        subtree1->tree_root = cursor->left;
        subtree2->tree_root = cursor;
        subtree2->tree_root->left = subtree1->tree_root->right;
        subtree1->tree_root->right = nullptr;
    }

    while(cursor != nullptr) {
        if(cursor->right != nullptr && cursor->right->inf == n) {
            subtree1->tree_root = cursor;
            subtree2->tree_root = cursor->right;
            subtree1->tree_root->right = nullptr;
            break;
        } else if(cursor->left != nullptr && cursor->left->inf == n) {
            subtree1->tree_root = cursor->left->left;
            subtree2->tree_root = cursor;
            subtree2->tree_root->left->left = nullptr;
            break;
        } else {
            if(cursor->inf < n)
                cursor = cursor->left;
            else
                cursor = cursor->right;
        }
    }
    if(cursor != nullptr) {
        src->tree_root = nullptr;
    }
}

