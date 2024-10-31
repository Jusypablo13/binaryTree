#include <iostream>
#include "binaryTree.h"

using namespace std;

int main(){
    BinaryTree tree;

    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 3);
    tree.root = tree.insert(tree.root, 7);
    tree.root = tree.insert(tree.root, 2);
    tree.root = tree.insert(tree.root, 4);
    tree.root = tree.insert(tree.root, 6);
    tree.root = tree.insert(tree.root, 8);
    
    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Preorder Traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorder(tree.root);
    cout << endl;

    int value;
    cout << "Enter value to search: ";
    cin >> value;
    Node* result = tree.search(tree.root, value);
    if (result != nullptr){
        cout << "Value " << value << " found in the tree." << endl;
    } else {
        cout << "Value " << value << " not found in the tree." << endl;
    }

    cout << "Enter value to delete: ";
    cin >> value;
    tree.root = tree.remove(tree.root, value);

    cout << "Inorder Traversal after deletion: ";
    tree.inorder(tree.root);
    cout << endl;
    
    return 0;
}