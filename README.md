BinaryTree Project

Overview

This project implements a Binary Search Tree (BST) in C++. It includes a BinaryTree class that provides the following functionalities:

	•	Insertion: Insert new nodes into the tree while maintaining BST properties.
	•	Search: Find if a specific value exists within the tree.
	•	Removal: Delete nodes from the tree, ensuring the tree remains a valid BST.
	•	Tree Traversals:
	•	In-order Traversal: Left subtree → Root → Right subtree.
	•	Pre-order Traversal: Root → Left subtree → Right subtree.
	•	Post-order Traversal: Left subtree → Right subtree → Root.

Contents

	•	binaryTree.h: Header file containing the Node struct and BinaryTree class declarations.
	•	binaryTree.cpp: Source file with implementations of the BinaryTree member functions.
	•	main.cpp: Sample program to demonstrate the usage of the BinaryTree class.
	•	Makefile: (Optional) Makefile for compiling the project.

Getting Started

Prerequisites

	•	C++ compiler supporting C++11 or higher (e.g., GCC, Clang).
	•	Basic understanding of compiling C++ programs from the command line or using an IDE.

Compilation Instructions

Using Command Line

Compile the project by including both main.cpp and binaryTree.cpp:

g++ -std=c++11 -g main.cpp binaryTree.cpp -o binaryTree

Or using Clang:

clang++ -std=c++11 -g main.cpp binaryTree.cpp -o binaryTree

Using a Makefile

If a Makefile is provided, compile the project by simply running:

make

This will generate an executable named binaryTree.

Running the Program

After successful compilation, run the executable:

./binaryTree

Usage

The BinaryTree class can be used to create and manipulate a binary search tree. Below is a brief explanation of how to use the class and its functions.

Creating a Tree

BinaryTree tree;

Inserting Nodes

tree.root = tree.insert(tree.root, value);

	•	Parameters:
	•	tree.root: The root of the tree (initially nullptr).
	•	value: The integer value to insert into the tree.

Searching for a Value

Node* result = tree.search(tree.root, value);
if (result != nullptr)
    std::cout << "Value found in the tree." << std::endl;
else
    std::cout << "Value not found in the tree." << std::endl;

Removing a Node

tree.root = tree.remove(tree.root, value);

	•	Parameters:
	•	tree.root: The root of the tree.
	•	value: The integer value to remove from the tree.

Tree Traversals

In-order Traversal

tree.inorder(tree.root);

Pre-order Traversal

tree.preorder(tree.root);

Post-order Traversal

tree.postorder(tree.root);

Each traversal function prints the node values to the console in the specified order.

Example

Below is an example of how to use the BinaryTree class in a program:

#include <iostream>
#include "binaryTree.h"

int main() {
    BinaryTree tree;

    // Insert values into the tree
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 3);
    tree.root = tree.insert(tree.root, 7);
    tree.root = tree.insert(tree.root, 2);
    tree.root = tree.insert(tree.root, 4);
    tree.root = tree.insert(tree.root, 6);
    tree.root = tree.insert(tree.root, 8);

    // Perform traversals
    std::cout << "In-order Traversal: ";
    tree.inorder(tree.root);
    std::cout << std::endl;

    std::cout << "Pre-order Traversal: ";
    tree.preorder(tree.root);
    std::cout << std::endl;

    std::cout << "Post-order Traversal: ";
    tree.postorder(tree.root);
    std::cout << std::endl;

    // Search for a value
    int value = 4;
    Node* result = tree.search(tree.root, value);
    if (result != nullptr)
        std::cout << "Value " << value << " found in the tree." << std::endl;
    else
        std::cout << "Value " << value << " not found in the tree." << std::endl;

    // Remove a node
    tree.root = tree.remove(tree.root, 3);
    std::cout << "In-order Traversal after removing 3: ";
    tree.inorder(tree.root);
    std::cout << std::endl;

    return 0;
}

Project Structure

.
├── binaryTree.h      // Header file with class and struct declarations
├── binaryTree.cpp    // Implementation of BinaryTree member functions
├── main.cpp          // Main program demonstrating BinaryTree usage
└── Makefile          // (Optional) Makefile for building the project

Functions Description

Node Struct

Represents a node in the binary search tree.

	•	Members:
	•	int data: The value stored in the node.
	•	Node* left: Pointer to the left child.
	•	Node* right: Pointer to the right child.

BinaryTree Class

Manages the binary search tree operations.

Members

	•	Node* root: Pointer to the root node of the tree.

Member Functions

	•	Constructor: Initializes root to nullptr.
	•	Node* insert(Node* node, int value): Inserts a new node with the given value into the tree rooted at node.
	•	Node* search(Node* node, int value): Searches for a node with the given value in the tree rooted at node.
	•	Node* remove(Node* node, int value): Removes the node with the given value from the tree rooted at node.
	•	void inorder(Node* node): Performs an in-order traversal starting from node.
	•	void preorder(Node* node): Performs a pre-order traversal starting from node.
	•	void postorder(Node* node): Performs a post-order traversal starting from node.