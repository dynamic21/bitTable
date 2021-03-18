#pragma once
#include <iostream>
#include "random.h"

using std::cout;
using std::endl;

class bitTable
{
private:
    unsigned int table = 0;
    int dimensions = 0;

public:
    bitTable(int size)
    {
        dimensions = size;
        for (int i = 0; i < dimensions; i++)
        {
            table |= random() * (unsigned int)1 << i;
        }
    }
    
    void print(){
        for (int i = 0; i < dimensions; i++)
        {
            cout << ((table << (31 - i)) >> 31) << endl;
        }
    }
};