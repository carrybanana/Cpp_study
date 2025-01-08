#ifndef MPRINT_H_
#define MPRINT_H_
#include <iostream>

class mprint
{
public:
    virtual void print() = 0;
};

class print1 : public mprint
{
public:
    void print();
};

class print2 : public mprint
{
public:
    void print();
};

#endif
