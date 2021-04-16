#include "BinaryTreeAVL.h"
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

BinaryTreeAVL::BinaryTreeAVL():BinaryTree(){}
BinaryTreeAVL::~BinaryTreeAVL(){
    BinaryTree::deleteTree(root);
    cout<<"AVL-Tree deleted"<<endl;
}

void BinaryTreeAVL::insert(const char *value){
    if (root == NULL){
        root = new treeNode;
        root -> key = value;
        root -> count = 1;
        root -> left = NULL;
        root -> right = NULL;
    }
    else {
        root = insertNode(value, root);
    }
}
treeNode *BinaryTreeAVL::insertNode(const char *value, treeNode *node){

    if (strcmp(value,node->key) < 0){
        if (node ->left != NULL){
           node -> left = insertNode(value,node->left);
        }
        else{
            node -> left = new treeNode;
            node -> left -> key = value;
            node -> left -> count = 1;
            node -> left -> left = NULL;
            node -> left -> right = NULL;
            return node;
        }
    }
    else if (strcmp(value,node->key) == 0){
        node -> count +=1;
    }
    else if (strcmp(value, node->key) > 0){
        if (node ->right != NULL){
           node -> right = insertNode(value,node->right);
        }
        else{
            node -> right = new treeNode;
            node -> right -> key = value;
            node -> right -> count = 1;
            node -> right -> left = NULL;
            node -> right -> right = NULL;
            return node;
        }
    }
    if (difference(node) > 1 && strcmp(value, node -> left -> key) < 0){
        return rightRotation(node);
    }
    if (difference(node) < -1 && strcmp(value, node -> right -> key) > 0){
        return leftRotation(node);
    }
    if (difference(node) > 1 && strcmp(value, node -> left -> key) > 0){
        node -> left = leftRotation(node -> left);
        return rightRotation(node);
    }
    if (difference(node) < -1 && strcmp(value, node -> right -> key) < 0){
        node -> right = rightRotation(node -> right);
        return leftRotation(node);
    }
    return node;
}

int BinaryTreeAVL::calcHeight(treeNode *node){
    int height = 0;

    if (node != NULL){
        int heightLeft = calcHeight(node -> left);
        int heightRight = calcHeight(node -> right);
        int maxHeight = max(heightLeft, heightRight);
        height =maxHeight + 1;
    }

    return height;
}

int BinaryTreeAVL::difference(treeNode * node){
    int heightLeft = calcHeight(node -> left);
    int heightRight = calcHeight(node -> right);
    int balanceFactor = heightLeft - heightRight;
    return balanceFactor;
}

treeNode *BinaryTreeAVL::leftRotation(treeNode *node){
    treeNode *temp1 = node -> right;
    treeNode *temp2 = temp1 -> left;
    temp1 -> left = node;
    node -> right = temp2;
    return temp1;
}

treeNode *BinaryTreeAVL::rightRotation(treeNode *node){
    treeNode *temp1 = node -> left;
    treeNode *temp2 = temp1 -> right;
    temp1 -> right = node;
    node -> left = temp2;
    return temp1;
}
void BinaryTreeAVL::dlt(const char *value){
    root = dltNode(value, root);
}
treeNode *BinaryTreeAVL::dltNode(const char *value, treeNode *node){
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

     if (difference(node) > 1 && difference(node -> left) >= 0){
        return rightRotation(node);
    }
    if (difference(node) < -1 && difference(node -> left) <= 0){
        return leftRotation(node);
    }
    if (difference(node) > 1 && difference(node -> right) < 0){
        node -> left = leftRotation(node -> left);
        return rightRotation(node);
    }
    if (difference(node) < -1 && difference(node -> right) > 0){
        node -> right = rightRotation(node -> right);
        return leftRotation(node);
    }

    return node;
}