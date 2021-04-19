#include "SortedArray.h"

SortedArray::SortedArray():NonSortedArray()
{

}
SortedArray::~SortedArray()
{
   for (int i = 0; i<numOfEl; i++)
    {
        delete elements[i];
        delete count[i];
    }
}

void SortedArray::Swap(int *xp, int *yp) 
{ 
    char temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}  

void SortedArray::Sort() 
{ 
    
    for (int i = 0; i < numOfEl-1; i++)           
    // Last i elements are already in place 
    for (int j = 0; j < numOfEl-i-1; j++) 
        if (elements[j] > elements[j+1]) 
            Swap(&elements[j], &elements[j+1]); 
}

int SortedArray::Search(const char& x)
{
  int l,r;
  l=0;
  r=numOfEl-1;
  while (l <= r)
  {
    int m = l + (r-l)/2;
  
    // Check if x is present at mid
    if (elements[m] == x) 
        count[m]++;
        return m;  
  
    // If x greater, ignore left half  
    if (elements[m] < x) 
        l = m + 1; 
  
    // If x is smaller, ignore right half 
    else 
         r = m - 1; 
  }
  
  // if we reach here, then element was not present
  return -1; 
}
void SortedArray::Insert(const char& word)
{

    // Cannot insert more elements if n is already
    // more than or equal to capcity
    if (numOfEl >= size)
    {
        NonSortedArray::Expand();
        int i;
        for (i = numOfEl - 1; (i >= 0 && elements[i] > word); i--)
            elements[i + 1] = elements[i];
 
        elements[i + 1] = word;
        numOfEl++;
    } 
    else
    {
        int i;
        for (i = numOfEl - 1; (i >= 0 && elements[i] > word); i--)
            elements[i + 1] = elements[i];
    
        elements[i + 1] = word;
        numOfEl++;
    }
}

bool SortedArray::Delete(const char &word)
{

    NonSortedArray::Delete(word);
    /*char temp=word;
    // Find position of element to be deleted
    int pos = Search(temp);
 
    if (pos == -1)
    {
        cout << "Element not found";
        return false;
    }
    // Deleting element
    int i;
    for (i = pos; i < numOfEl - 1; i++)
        elements[i] = elements[i + 1];
 
    numOfEl--;
    return true;*/

}