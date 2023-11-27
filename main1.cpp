// main1.cpp
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
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    BinarySearchTree bst;

    cout << "Original list: ";
    for (int i = 0; i < 35; i++) {
        int num = rand() % 100 + 1;
        cout << num << " ";
        bst.insert(num);
    }

    cout << endl << endl;

    cout << "Preorder: " << endl;
    bst.preorder();
    cout << endl << endl;

    cout << "Inorder: " << endl;
    bst.inorder();
    cout << endl << endl;

    cout << "Postorder: " << endl;
    bst.postorder();
    cout << endl << endl;

    
    int deleteCount;
    cout << "Enter the number of times you want to delete a node: ";
    cin >> deleteCount;

    
    for (int i = 0; i < deleteCount; i++)
    {
        int deleteVal;
        cout << "Enter a node value to delete: ";
        cin >> deleteVal;
        bst.deleteNode(deleteVal);

        
        cout << "Updated tree after deleting " << deleteVal << " with postorder DFS: " << endl;
        bst.postorder();
        cout << endl << endl;
    }

   
    if (bst.isAVL())
    {
        cout << "The tree is an AVL tree." << endl;
    }
    else 
    {
        cout << "The tree is not an AVL tree." << endl;
    }

   
    bst.deleteTree();

    return 0;
}
