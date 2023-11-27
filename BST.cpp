// BST.cpp
//Samrana Sheikh
//11-27-2023
//CSDP 250 Project 5
/*Program Description :
*This C++ program implements a Binary Search Tree(BST) with a lot of operations such as deletion, tree traversal, insertion,
* and checking if the tree is an AVL tree or if it is not. The program shows
* the usage of the BinarySearchTree class through a main program,
* allowing users to interact with the tree data structure.
*/

#include "BST.h"
#include <iomanip>

using namespace std;

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree() 
{
    clear(root);
}

Node* BinarySearchTree::create(int val) 
{
    Node* newNode = new Node;
    newNode->num = val;
    newNode->leftNext = nullptr;
    newNode->rightNext = nullptr;
    return newNode;
}

Node* BinarySearchTree::insert(int val, Node* root) 
{
    if (root == nullptr)
    {
        return create(val);
    }
    else if (val > root->num)
    {
        root->rightNext = insert(val, root->rightNext);
    }
    else 
    {
        root->leftNext = insert(val, root->leftNext);
    }
    return root;
}

void BinarySearchTree::insert(int val)
{
    root = insert(val, root);
}

Node* BinarySearchTree::deleteNode(int val, Node* root) 
{
    if (root == nullptr) 
    {
        return root;
    }

    if (val < root->num)
    {
        root->leftNext = deleteNode(val, root->leftNext);
    }
    else if (val > root->num) 
    {
        root->rightNext = deleteNode(val, root->rightNext);
    }
    else {
        if (root->leftNext == nullptr) 
        {
            Node* temp = root->rightNext;
            delete root;
            return temp;
        }
        else if (root->rightNext == nullptr) 
        {
            Node* temp = root->leftNext;
            delete root;
            return temp;
        }

        Node* temp = root->rightNext;
        while (temp->leftNext != nullptr)
        {
            temp = temp->leftNext;
        }

        root->num = temp->num;
        root->rightNext = deleteNode(temp->num, root->rightNext);
    }

    return root;
}

void BinarySearchTree::deleteNode(int val) 
{
    root = deleteNode(val, root);
}

void BinarySearchTree::deleteTree(Node* root) 
{
    if (root) 
    {
        deleteTree(root->leftNext);
        deleteTree(root->rightNext);
        delete root;
    }
}

void BinarySearchTree::deleteTree() 
{
    deleteTree(root);
    root = nullptr;
}

void BinarySearchTree::preorder(Node* root)
{
    if (root == nullptr) 
    {
        return;
    }
    cout << root->num << " ";
    preorder(root->leftNext);
    preorder(root->rightNext);
}

void BinarySearchTree::preorder()
{
    preorder(root);
}

void BinarySearchTree::inorder(Node* root)
{
    if (root == nullptr) 
    {
        return;
    }
    inorder(root->leftNext);
    cout << root->num << " ";
    inorder(root->rightNext);
}

void BinarySearchTree::inorder() 
{
    inorder(root);
}

void BinarySearchTree::postorder(Node* root) 
{
    if (root == nullptr) 
    {
        return;
    }
    postorder(root->leftNext);
    postorder(root->rightNext);
    cout << root->num << " ";
}

void BinarySearchTree::postorder()
{
    postorder(root);
}

bool BinarySearchTree::isAVL(Node* node) 
{
    if (node == nullptr)
    {
        return true;
    }

    int balance = getBalanceFactor(node);

    if (balance > 1 || balance < -1)
    {
        return false;
    }

    return isAVL(node->leftNext) && isAVL(node->rightNext);
}

bool BinarySearchTree::isAVL()
{
    return isAVL(root);
}

int BinarySearchTree::getHeight(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int leftHeight = getHeight(node->leftNext);
    int rightHeight = getHeight(node->rightNext);

    return 1 + max(leftHeight, rightHeight);
}

int BinarySearchTree::getBalanceFactor(Node* node) 
{
    if (node == nullptr) 
    {
        return 0;
    }

    return getHeight(node->leftNext) - getHeight(node->rightNext);
}

void BinarySearchTree::clear(Node* root) 
{
    if (root) {
        clear(root->leftNext);
        clear(root->rightNext);
        delete root;
    }
}
