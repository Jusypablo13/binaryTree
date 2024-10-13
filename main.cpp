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
    
    cout << "Inorder: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Preorder: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Postorder: ";
    tree.postorder(tree.root);
    cout << endl;

    
    int value;
    cout << "Ingrese el valor a buscar: ";
    cin >> value;
    Node* result = tree.search(tree.root, value);
    if (result != nullptr){
        cout << "El valor " << value << " fue encontrado" << endl;
    } else {
        cout << "El valor " << value << " no fue encontrado" << endl;
    }

    cout << "Ingrese el valor a eliminar: ";
    cin >> value;
    tree.root = tree.remove(tree.root, value);
    cout << "Inorder: ";
    tree.inorder(tree.root);
    cout << endl;
    
    return 0;
}