#ifndef Array_h
#define Array_h

class Array{

    private:
    const char **elements;    
    int size;
    int numOfEl;

    public:
    Array();

    ~Array();

    void ins(char *);
    void dlt(int);
    void dlt(char *);
    void srch(char *);
    void expand();
};
#endif