#pragma once
#include<iostream>
using namespace std;
template <typename T> class BST
{
private:
    T data;
    BST* left, * right;
public:

    /*BST();

    BST(T);


    BST* Insert(BST*, T);


    void Inorder(BST*);*/


    BST* search(BST* root, T key,int & counter)
    {
    
        // Base Cases: root is null or key is present at root
        if (root == NULL || root->data == key)
        {
            counter++;
            cout << "Found :";
            cout << root->data << endl;;
            return root;
        }
            

        // Key is greater than root's key
        if (root->data < key)
        {
            return search(root->right, key,counter);
            counter++;
        }

        counter++;
        // Key is smaller than root's key
        return search(root->left, key, counter);
    }


    BST()
    {
        this->left = NULL;
        this->right = NULL;
    }


    BST(T value)
    {
        data = value;
        left = right = NULL;
    }

    BST* Insert(BST* root, T value)
    {
        if (!root) {

            return new BST(value);
        }

        // Insert data.
        if (value > root->data) {
            // Insert right node data, if the 'value'
            // to be inserted is greater than 'root' node data.

            // Process right nodes.
            root->right = Insert(root->right, value);
        }
        else {
            // Insert left node data, if the 'value'
            // to be inserted is greater than 'root' node data.

            // Process left nodes.
            root->left = Insert(root->left, value);
        }

        // Return 'root' node, after insertion.
        return root;
    }

    // Inorder traversal function.
    // This gives data in sorted order.
    void Inorder(BST* root)
    {
        if (!root) {
            return;
        }
        Inorder(root->left);
        cout << root->data << endl;
        Inorder(root->right);
    }

};