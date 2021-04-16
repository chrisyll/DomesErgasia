#include "BinaryTree.h"
#ifndef BinaryTreeAVL_h
#define BinaryTreeAVL_h


class BinaryTreeAVL: public BinaryTree{

    private:

    public:
    BinaryTreeAVL();
    ~BinaryTreeAVL();

    void insert(const char *);
    treeNode *insertNode(const char *, treeNode *);

    int calcHeight(treeNode *);
    int difference(treeNode *);

    treeNode *rightRotation(treeNode *);
    treeNode *leftRotation(treeNode *);

    void dlt(const char *);
    treeNode *dltNode(const char *, treeNode *);

};
#endif