#include "binaryTree.h"

Node::Node(int value){
    data = value;
    left = nullptr;
    right = nullptr;
}

BinaryTree::BinaryTree(){
    root = nullptr;
}

//Insertar un nodo en el árbol
Node* BinaryTree::insert(Node* node, int value){
    if (node == nullptr){
        return new Node(value);
    }

    if (value < node->data){
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }

    return node;
}

//Buscar un nodo en el árbol
Node* BinaryTree::search(Node* node, int value){
    if (node == nullptr || node->data == value){
        return node;
    }

    if (value < node->data){
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }   
}

//Encontrar el nodo con el valor mínimo
Node* findMin(Node* node){
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}

//Eliminar un nodo del árbol
Node* BinaryTree::remove(Node* node, int value){
    if (node == nullptr){
        return node;
    }

    if (value < node->data){
        node->left = remove(node->left, value);
    } else if (value > node->data){
        node->right = remove(node->right, value);
    } else {
        //Nodo con un solo hijo o sin hijos
        if (node->left == nullptr){
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr){
            Node* temp = node->left;
            delete node;
            return temp;
        }
        //Nodo con dos hijos
        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }
    return node;
}

//Recorrido en orden Izquierda - Raíz - Derecha
void BinaryTree::inorder(Node* node){
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

//Recorrido en preorden Raíz - Izquierda - Derecha
void BinaryTree::preorder(Node* node){
    if (node == nullptr) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

//Recorrido en postorden Izquierda - Derecha - Raíz
void BinaryTree::postorder(Node* node){
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}