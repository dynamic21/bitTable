#include "bitTable.h"

int main()
{
    int inputSize = 5;
    bitTable keptBitTable(inputSize);
    while (true)
    {
        bitTable newBitTable = keptBitTable;
        newBitTable.mutate();
        keptBitTable.print();
        newBitTable.print();
        int keptScore = 0;
        int newScore = 0;
        for (int i = 0; i < 32; i++)
        {
            unsigned int input = 0;
            bool output = false;
            // cout << "out: ";
            for (int j = 0; j < inputSize; j++)
            {
                // bool out = false;
                if (random())
                {
                    input |= 1 << j;
                    // out = true;
                    output = !output;
                }
                // cout << out << " ";
            }
            // cout << endl;
            // cout << "output: " << output << endl;
            // cout << "input: " << input << endl;
            // cout << "keptBitTable: " << keptBitTable.getTableBit(input) << endl;
            // cout << "newBitTable: " << newBitTable.getTableBit(input) << endl;
            // cout << endl;
            keptScore += output == keptBitTable.getTableBit(input);
            newScore += output == newBitTable.getTableBit(input);
        }
        cout << "keptBitTable: " << keptScore << endl;
        cout << "newBitTable: " << newScore << endl;
        cout << endl;
        if (newScore > keptScore)
        {
            keptBitTable = newBitTable;
        }
    }

    // for (int i = 0; i < 10; i++)
    // {
    //     startTimer();
    //     for (int i = 0; i < 100000000; i++)
    //     {
    //         newBitTable.getBit(5);
    //     }
    //     cout << "time: " << stopTimer() << endl;
    // }
}