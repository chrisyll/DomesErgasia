#include <Array.h>

Array::Array(){
    size = 100;
    numOfEl = 0;
    elements = new const char*[size];
}

Array::~Array(){
    for (int i = 0; i<numOfEl; i++){
        delete elements[i];
    }
    delete[]elements;
}

void Array::expand(){
    size *=2;
    char **temp = new char*[size];
    for (int i = 0; i<numOfEl;i++){
        temp[i] = new char(*elements[i]);
    }
    for (int i = 0; i<numOfEl; i++){
        delete elements[i];
    }
    delete[]elements;
    elements = temp;
}
