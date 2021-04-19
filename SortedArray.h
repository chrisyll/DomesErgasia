#include "NonSortedArray.h"
#ifndef SortedArray_h
#define SortedArray_h

class SortedArray: public NonSortedArray
{
  public:
    SortedArray();
    ~SortedArray();

    void Sort();
    void Swap(int*,int*);

    int Search(const char&);
    void Insert(const char&);
    bool Delete(const char&);
};
#endif