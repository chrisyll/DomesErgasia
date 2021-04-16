#include "BinaryTree.h"
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;


BinaryTree::BinaryTree(){
    root = NULL;
}
BinaryTree::~BinaryTree(){
    deleteTree(root);
    cout<<"B-Tree deleted";
}

bool BinaryTree::deleteTree(treeNode *n){
    if (n == NULL){
        return true;
    }
    deleteTree(n -> left);
    deleteTree(n -> right);
    delete n;
    return true;
}

void BinaryTree::insert(const char *value){
    if (root == NULL){
        root = new treeNode;
        root -> key = value;
        root -> count = 1;
        root -> left = NULL;
        root -> right = NULL;
    }
    else {
        insertNode(value , root);
    }
}
treeNode *BinaryTree::insertNode(const char *value, treeNode *node){
    if (strcmp(value, node->key ) < 0){
        if (node -> left != NULL){
            insertNode(value, node->left);
        }
        else {
            node -> left = new treeNode;
            node -> left -> key = value;
            node -> left -> count = 1;
            node -> left -> left = NULL;
            node -> left -> right = NULL;
        }
    }
    else if (strcmp(value, node->key ) > 0){
        if (node -> right != NULL){
            insertNode(value, node->right);
        }
        else {
            node -> right = new treeNode;
            node -> right -> key = value;
            node -> right -> count = 1;
            node -> right -> left = NULL;
            node -> right -> right = NULL;
        }
    }
    else if (strcmp(value, node -> key) == 0){
        node -> count +=1;
    }
    return node;
}

bool BinaryTree::search(const char *value){
    if (searchNode(value, root)){
        return true;
    }
    else {
        return false;
    }
}

bool BinaryTree::searchNode(const char *value, treeNode *node){
    while (node != NULL){
        if (strcmp(value, node -> key) > 0){
            node = node -> right;
        }
        else if(strcmp(value, node -> key) < 0){
            node = node -> left;
        }
        else {
            cout<<"word was found"<<endl;
            return true;
        }
    }
    cout<<"word was not found"<<endl;
    return false;
}

void BinaryTree::inOrder(){
    inOrder(root);
}
void BinaryTree::inOrder(treeNode *node){
    if (node == NULL){
        return;
    }
    inOrder(node -> left);
    cout<<(node -> key)<<endl;
    inOrder(node -> right);
}

void BinaryTree::preOrder(){
    preOrder(root);
}
void BinaryTree::preOrder(treeNode *node){
    if (node == NULL){
        return;
    }
    cout<<(node -> key)<<endl;
    preOrder(node -> left);
    preOrder(node -> right);
}

void BinaryTree::postOrder(){
    postOrder(root);
}
void BinaryTree::postOrder(treeNode *node){
    if (node == NULL){
        return;
    }
    postOrder(node -> left);
    postOrder(node -> right);
    cout<<(node -> key)<<endl;
}

void BinaryTree::dlt(const char *value){
    if(root !=NULL){
        dltNode(value, root);
    }
    else {
        cout<<"The tree is empty!"<<endl;
    }
}

treeNode *BinaryTree::dltNode(const char *value, treeNode *node){
    cout<<"diagrafoume"<<endl;
    if (node == NULL){
        return NULL;
    }
    if (strcmp(value, node -> key) < 0){
        node -> left = dltNode(value, node -> left);
    }
    else if(strcmp(value, node -> key) > 0){
        node -> right = dltNode(value, node -> right);
    }
    else {
        if (node -> left == NULL){
            treeNode *temp = node -> right;
            delete node;
            return temp;
        }
        else if (node -> right == NULL){
            treeNode *temp = node -> left;
            delete node;
            return temp;
        }
        else {
            treeNode *temp = minNode(node -> right);
            node -> key = temp -> key;
            node -> right = dltNode(temp -> key, node -> right);
        }
    }
}
treeNode *BinaryTree::minNode(treeNode *node){
    if (node -> left != NULL){
        minNode(node -> left);
    }
    else {
        return node;
    }
}