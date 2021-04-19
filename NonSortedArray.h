#ifndef NonSortedArray_h
#define NonSortedArray_h

class NonSortedArray
{
    protected:
      const char* elements[];
      const int* count[];
      int size;
      int numOfEl;
    public:

      NonSortedArray();
      ~NonSortedArray();

      int getsize();
      int getnumOfEl();     

      virtual void Insert(const char&);
      virtual bool Delete(const char&);
      virtual int Search(const char&);

      void Expand();

};
#endif