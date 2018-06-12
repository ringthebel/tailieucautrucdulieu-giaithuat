#include "BST.h"
#include <iostream>

using namespace std;

int main() {
    BST tree;
    tree.insert(25);
    tree.insert(12);
    tree.insert(21);
    tree.insert(7);
    tree.insert(10);
    tree.insert(36);
    tree.insert(45);
    tree.insert(31);
    tree.insert(27);
    tree.insert(33);
    tree.insert(24);
    tree.insert(13);
    tree.insert(14);
    tree.insert(14);
    tree.print();
    cout << endl;
    cout << "Height of tree: " << tree.height() << endl;
    cout << tree.maxPath() << endl;
    if(tree.isBalance()) {
        cout << "Tree is balanced." << endl;
    } else {
        cout << "Tree is not balanced." << endl;
    }
    tree.remove(12);
    tree.remove(12);
    tree.print();
    cout << endl;
    tree.remove(21);
    tree.remove(14);
    tree.remove(24);
    tree.print();
    cout << endl;
    if(tree.isBalance()) {
        cout << "Tree is balanced." << endl;
    } else {
        cout << "Tree is not balanced." << endl;
    }

    BST tree1, tree2;
    divide(&tree, &tree1, &tree2, 13);
    tree1.print();
    cout << endl;
    tree2.print();
    cout << endl;
    cout << tree.isEmpty() << endl;
    tree1.clear();
    tree2.clear();
    return 0;
}
