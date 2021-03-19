#include "bitComponent.h"

int main()
{
    // for (int i = 0; i < 10; i++)
    // {
    //     startTimer();
    //     for (int j = 0; j < 10000000; j++)
    //     {
    //         unsigned int num = 0;
    //         num |= random() << 10;
    //     }
    //     cout << "time: " << stopTimer() << endl;
    // }
    // bitComponent newBitComponent;
    // newBitComponent.print();
    // newBitComponent.mutate();
    // newBitComponent.print();
    // newBitComponent.mutate();
    // newBitComponent.print();
    // newBitComponent.mutate();
    // newBitComponent.print();
    // vector<bool> input = {1, 0};
    // newBitComponent.evaluateInput(&input);
    // return 0;
    int inputSize = 2;
    bitComponent keptBitComponent;
    while (true)
    {
        bitComponent newBitComponent(&keptBitComponent);
        newBitComponent.mutate();
        keptBitComponent.print();
        newBitComponent.print();
        int keptScore = 0;
        int newScore = 0;
        for (int i = 0; i < 4; i++)
        {
            vector<bool> input;
            bool output = false;
            // cout << "out: ";
            for (int j = 0; j < inputSize; j++)
            {
                // bool out = false;
                input.push_back(random());
                if (input[j])
                {
                    // out = true;
                    output = !output;
                }
                // cout << out << " ";
            }
            // cout << endl;
            // cout << "output: " << output << endl;
            // cout << "input: " << input << endl;
            // cout << "!!keptBitComponent: " << keptBitComponent.evaluateInput(&input)[0] << endl;
            // cout << "!!newBitComponent: " << newBitComponent.evaluateInput(&input)[0] << endl;
            // cout << endl;
            keptScore += output == keptBitComponent.evaluateInput(&input)[0];
            newScore += output == newBitComponent.evaluateInput(&input)[0];
        }
        cout << "keptBitTable: " << keptScore << endl;
        cout << "newBitTable: " << newScore << endl;
        cout << endl;
        if (newScore > keptScore)
        {
            keptBitComponent = newBitComponent;
            keptBitComponent.print();
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