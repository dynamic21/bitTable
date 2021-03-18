#pragma once
#include <iostream>
#include "random.h"

using std::cout;
using std::endl;

class bitTable
{
private:
    int dimensions = 5; // max = 5
    unsigned int length = 0;
    unsigned int rate = 0;
    unsigned int table = 0;

public:
    bitTable(int size)
    {
        dimensions = size;
        length = 1 << dimensions;
        for (int i = 0; i < length; i++)
        {
            if (random())
                table |= 1 << i;
        }
        for (int i = 0; i < 32; i++)
        {
            if (random())
                rate |= 1 << i;
        }
    }

    bool getTableBit(int index)
    {
        return table >> index & 1;
    }

    bool getRateBit(int index)
    {
        return rate >> index & 1;
    }

    void mutate()
    {
        rate ^= 1 << random(length);
        if (rate == 0xffffffff)
            rate ^= 1 << random(length);
        while (getRateBit(random(32)))
            table ^= 1 << random(length);
    }

    void print()
    {
        // cout << "dimensions: " << dimensions << endl;
        // cout << "length: " << length << endl;
        cout << "rate: ";
        for (int i = 0; i < 32; i++)
        {
            cout << getRateBit(i) << " ";
        }
        cout << endl;
        cout << "table: ";
        for (int i = 0; i < length; i++)
        {
            cout << getTableBit(i) << " ";
        }
        cout << endl;
    }
};