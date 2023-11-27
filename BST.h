// BST.h
//Samrana Sheikh
//11-27-2023
//CSDP 250 Project 5
/*Program Description :
*This C++ program implements a Binary Search Tree(BST) with a lot of operations such as deletion, tree traversal, insertion,
* and checking if the tree is an AVL tree or if it is not. The program shows
* the usage of the BinarySearchTree class through a main program,
* allowing users to interact with the tree data structure.
*/

#ifndef BST_H
#define BST_H

#include <iostream>

struct Node 
{
    int num;
    Node* leftNext;
    Node* rightNext;
};

class BinarySearchTree 
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int val);
    void deleteNode(int val);
    void deleteTree();
    void preorder();
    void inorder();
    void postorder();
    bool isAVL();

private:
    Node* root;
    Node* create(int val);
    Node* insert(int val, Node* node);
    Node* deleteNode(int val, Node* root);
    void deleteTree(Node* root);
    void preorder(Node* node);
    void inorder(Node* node);
    void postorder(Node* node);
    int getHeight(Node* node);
    int getBalanceFactor(Node* node);
    bool isAVL(Node* node);
    void clear(Node* node);
};

#endif
