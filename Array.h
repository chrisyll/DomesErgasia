#ifndef Array_h
#define Array_h

struct str {
    const char *p;
};

class Array{

    private:
    str array[100];    //you do not specify a size but i've actually found it works pretty well.
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