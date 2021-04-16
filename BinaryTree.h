#ifndef BinaryTree_h
#define BinaryTree_h

struct treeNode{
    const char *key;
    int count;
    treeNode *left;
    treeNode *right;
    };

class BinaryTree{

    protected:
    treeNode *root;

    public:
    BinaryTree();
    ~BinaryTree();

    bool deleteTree(treeNode *);
    virtual void insert(const char *);
    virtual treeNode *insertNode(const char*, treeNode *); //change to void

    bool search(const char *);
    bool searchNode(const char *, treeNode *);

    void inOrder();
    void inOrder(treeNode *);

    void preOrder();
    void preOrder(treeNode *);

    void postOrder();
    void postOrder(treeNode *);

    virtual void dlt(const char *);
    virtual treeNode *dltNode(const char *, treeNode *);
    treeNode *minNode(treeNode *);

};

#endif