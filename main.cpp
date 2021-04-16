#include <iostream>
#include <cstring>
#include <stdio.h>
#include "BinaryTree.h"
#include "BinaryTreeAVL.h"

using namespace std;

void changeData(int * data){
    data[0] = 45;
 }

int main(){
    
    int *data = new int[5];
    data[1] = 5;
    changeData(data);
    cout<<data[0]<<endl;


    return 0;
}