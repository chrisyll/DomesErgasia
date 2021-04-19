#include "Hasing.h"
#include <cstring>


Hashing::Hashing(){
    size = 500;
    array = new char[size];
}


// Horner's rule variation //
int Hashing::hashFunction(const char *value){
    int hashValue = 0;
    for (int i = strlen(value)-1; i >= 0; i--){
        hashValue = hashValue*4 + (value[i] - '0');
    }
    while (hashValue%Hashing::size != NULL){
        hashValue++;
    }
    return (hashValue%Hashing::size);
}