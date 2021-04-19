#include <iostream>
#include <cstring>
#include <stdio.h>
#include "BinaryTree.h"
#include "BinaryTreeAVL.h"

using namespace std;
struct str {
    const char *p;
};

int main(void){
    
    str array[50];
    array[0].p = "this";
    array[1].p = "that";

    delete array->p;
    cout<<array[1].p<<endl;

    return 0;
}