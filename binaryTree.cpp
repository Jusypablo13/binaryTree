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

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    //Rotaciones
    if (balance > 1 && value < node->left->data){
        return rightRotate(node);
    }
    if (balance < -1 && value > node->right->data){
        return leftRotate(node);
    }
    if (balance > 1 && value > node->left->data){
        return leftRightRotate(node);
    }
    if (balance < -1 && value < node->right->data){
        return rightLeftRotate(node);
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
        if (node->left == nullptr || node->right == nullptr){
            Node* temp = node->left ? node->left : node->right;

            if (temp == nullptr){
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }
    if (node == nullptr) return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = balanceFactor(node);

    //Rotaciones
    //Izquierda Izquierda
    if (balance > 1 && balanceFactor(node->left) >= 0)
        return rightRotate(node);

    //Izquierda Derecha
    if (balance > 1 && balanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //Deracha Derecha
    if (balance < -1 && balanceFactor(node->right) <= 0)
        return leftRotate(node);

    //Derecha Izquierda
    if (balance < -1 && balanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
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

//Calcular la altura de un nodo
int BinaryTree::height(Node* node){
    if(node == nullptr){
        return 0;
    }
    return node->height;
}

//Calcular el factor de balance de un nodo
int BinaryTree::balanceFactor(Node* node){
    if(node == nullptr){
        return 0;
    }
    return height(node->left) - height(node->right);
}

//Rotación simple derecha
Node* BinaryTree::rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

//Rotación simple izquierda
Node* BinaryTree::leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

//Rotación doble izquierda-derecha
Node* BinaryTree::leftRightRotate(Node* node){
    node->left = leftRotate(node->left);
    return rightRotate(node);
}

//Rotación doble derecha-izquierda
Node* BinaryTree::rightLeftRotate(Node* node){
    node->right = rightRotate(node->right);
    return leftRotate(node);
}