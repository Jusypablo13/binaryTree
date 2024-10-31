#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value);
};

class BinaryTree {
public:
    Node* root;

    BinaryTree();
    Node* insert(Node* node, int value);
    Node* search(Node* node, int value);
    Node* remove(Node* node, int value);
    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);
    int height(Node* node);
    int balanceFactor(Node* node);
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    Node* leftRightRotate(Node* node);
    Node* rightLeftRotate(Node* node);
};

#endif // BINARYTREE_H
