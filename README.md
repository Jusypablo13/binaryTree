# AVL Tree Project

## Overview

This project implements an AVL Tree in C++. The BinaryTree class supports various AVL Tree functionalities, including automatic balancing through rotations, as well as basic operations like insertion, deletion, and search.

### Key Features

	•	Insertion: Inserts new nodes while maintaining AVL Tree balance using rotations (single and double).
	•	Search: Finds if a specific value exists in the tree.
	•	Removal: Deletes nodes while rebalancing the tree to retain AVL properties.
	•	Tree Traversals:
	•	In-order Traversal: Left subtree → Root → Right subtree.
	•	Pre-order Traversal: Root → Left subtree → Right subtree.
	•	Post-order Traversal: Left subtree → Right subtree → Root.

### AVL Tree Rotations

To keep the tree balanced, the following rotations are implemented:

	•	Left Rotation: Balances the tree when the right subtree is too tall.
	•	Right Rotation: Balances the tree when the left subtree is too tall.
	•	Left-Right Rotation: A combination of left and right rotations for specific imbalances.
	•	Right-Left Rotation: A combination of right and left rotations for specific imbalances.

## Project Contents

	•	binaryTree.h: Header file with the Node struct and BinaryTree class declarations.
	•	binaryTree.cpp: Source file containing BinaryTree class function implementations, including balancing rotations.
	•	main.cpp: Sample program demonstrating the usage of the BinaryTree class.
	•	README.md: Documentation file for the project.
	•	.vscode/: Directory for VS Code workspace settings (optional).
	•	main.dSYM/: Debug symbols generated during compilation on macOS (optional).

## Getting Started

### Prerequisites

	•	C++ compiler with C++11 or higher (e.g., GCC, Clang).
	•	Familiarity with compiling C++ programs from the command line or using an IDE.

Compilation Instructions

Using Command Line

Compile the project by running:

g++ -std=c++11 -g main.cpp binaryTree.cpp -o main

or, if you prefer Clang:

clang++ -std=c++11 -g main.cpp binaryTree.cpp -o main

Using a Makefile

If you have a Makefile in the project directory, you can simply run:

make

This will generate an executable named main.

Running the Program

After compiling, you can run the executable:

./main

Usage

The BinaryTree class allows you to create and manipulate an AVL tree. Here’s a quick guide to using its functions.

Creating a Tree

BinaryTree tree;

Inserting Nodes

tree.root = tree.insert(tree.root, value);

	•	Parameters:
	•	tree.root: The root of the tree (initially nullptr).
	•	value: The integer value to insert.

## Searching for a Value

Node* result = tree.search(tree.root, value);
if (result != nullptr)
    std::cout << "Value found in the tree." << std::endl;
else
    std::cout << "Value not found in the tree." << std::endl;

Removing a Node

tree.root = tree.remove(tree.root, value);

	•	Parameters:
	•	tree.root: The root of the tree.
	•	value: The integer value to remove.

## Tree Traversals

	•	In-order Traversal: tree.inorder(tree.root);
	•	Pre-order Traversal: tree.preorder(tree.root);
	•	Post-order Traversal: tree.postorder(tree.root);

Each traversal function prints node values to the console in the specified order.

Example

#include <iostream>
#include "binaryTree.h"

int main() {
    BinaryTree tree;

    // Insert values into the AVL tree
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
├── README.md         // Project documentation

Function Descriptions

## Node Struct

Represents a node in the AVL tree.

	•	Members:
	•	int data: The value stored in the node.
	•	Node* left: Pointer to the left child.
	•	Node* right: Pointer to the right child.
	•	int height: The height of the node, important for balancing.

## BinaryTree Class

### Manages the AVL tree operations and balancing.

	•	Members:
	•	Node* root: Pointer to the root node of the tree.
	•	Member Functions:
	•	Constructor: Initializes root to nullptr.
	•	Node* insert(Node* node, int value): Inserts a new node and balances the AVL tree if needed.
	•	Node* search(Node* node, int value): Searches for a node with the specified value.
	•	Node* remove(Node* node, int value): Removes a node and rebalances the AVL tree if needed.
	•	Rotations:
	•	Node* rightRotate(Node* y): Performs a single right rotation.
	•	Node* leftRotate(Node* x): Performs a single left rotation.
	•	Node* leftRightRotate(Node* node): Performs a double left-right rotation.
	•	Node* rightLeftRotate(Node* node): Performs a double right-left rotation.
	•	Traversals:
	•	void inorder(Node* node): In-order traversal from node.
	•	void preorder(Node* node): Pre-order traversal from node.
	•	void postorder(Node* node): Post-order traversal from node.