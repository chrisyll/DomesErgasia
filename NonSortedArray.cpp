#include "NonSortedArray.h"
#include <iostream>
using namespace std;

NonSortedArray::NonSortedArray()
{
    size = 100;
    numOfEl = 0;
    elements = new const char*[size];
    count = new const int*[size];
    for(int i=0; i<numOfEl; i++)
      count[i]=0;
}

NonSortedArray::~NonSortedArray()
{
    for (int i = 0; i<numOfEl; i++)
    {
        delete elements[i];
        delete count[i];
    }
}
int NonSortedArray::getsize()
{
  return size;
}
int NonSortedArray::getnumOfEl()
{
  return numOfEl;
}     

int NonSortedArray::Search(const char &word)
{
  for(int i=0; i<numOfEl; i++)
  {
    if(elements[i]==word)
    {
      count[i]++;
      return i;
    }
  }
  return -1;
}

bool NonSortedArray::Delete(const char &word)
{
  /*  int i;
    for (i=0; i<numOfEl; i++)
    {
      if (elements[i] == word)
         break;
    }
   if (i < numOfEl)
   {
     numOfEl = numOfEl - 1;
     for (int j=i; j<numOfEl; j++)
        elements[j] = elements[j+1];
   }*/
   
    char temp=word;
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
    return true;

}

void NonSortedArray::Insert(const char &word)
{
  if (numOfEl>=size)
  { 
    Expand();
    elements[numOfEl]=word;
    numOfEl++;
  }
  else
  {
    elements[numOfEl]=word;
    numOfEl++;
  }
}
void NonSortedArray::Expand()
{
    size *=2;
    char **temp = new char*[size];
    for (int i = 0; i<numOfEl;i++)
    {
        temp[i] = new char(*elements[i]);
    }
    for (int i = 0; i<numOfEl; i++)
    {
        delete elements[i];
    }
    elements = temp;
}