#pragma once
#include <vector>
#include "bitTable.h"

using std::vector;

class bitComponent
{
private:
    bool linear = true;
    unsigned int inputLength = 0;
    vector<bitTable *> bitTables;
    vector<unsigned int> outputIndexes;
    vector<vector<unsigned int>> connections;

public:
    bitComponent(int inputSize = 2, int outputSize = 1)
    {
        // linear = random();
        inputLength = 2;
        outputIndexes.push_back(4);
        for (int i = 0; i < 3; i++)
            bitTables.push_back(new bitTable(2));
        connections.push_back({0, 1});
        connections.push_back({0, 2});
        connections.push_back({3, 2});
    }

    bitComponent(bitComponent *copyBitComponent)
    {
        linear = copyBitComponent->linear;
        inputLength = copyBitComponent->inputLength;
        for (int i = 0; i < copyBitComponent->outputIndexes.size(); i++)
            outputIndexes.push_back(copyBitComponent->outputIndexes[i]);

        for (int i = 0; i < copyBitComponent->bitTables.size(); i++)
            bitTables.push_back(new bitTable(copyBitComponent->bitTables[i]));

        for (int i = 0; i < copyBitComponent->connections.size(); i++)
        {
            connections.push_back({});
            for (int j = 0; j < copyBitComponent->connections[i].size(); j++)
                connections[i].push_back(copyBitComponent->connections[i][j]);
        }
    }

    vector<bool> evaluateInput(vector<bool> *inputs)
    {
        vector<bool> output;
        vector<bool> tableEvaluated(bitTables.size(), false);
        vector<bool> tableOutput(bitTables.size(), false);
        for (int i = 0; i < outputIndexes.size(); i++)
            output.push_back(evaluateBitTable(inputs, outputIndexes[i], &tableEvaluated, &tableOutput));

        return output;
    }

    bool evaluateBitTable(vector<bool> *baseInputs, int index, vector<bool> *tableEvaluated, vector<bool> *tableOutput)
    {
        if (index < inputLength)
        {
            // cout << "start: " << index << " is " << (*baseInputs)[index] << endl;
            return (*baseInputs)[index];
        }
        index -= inputLength;
        // cout << "index: " << index << endl;
        if ((*tableEvaluated)[index])
        {
            // cout << "done: " << index << " is " << (*tableOutput)[index] << endl;
            return (*tableOutput)[index];
        }
        unsigned int input = 0;
        for (int i = 0; i < connections[index].size(); i++)
        {
            // cout << "!!!!!!asking " << connections[index][i] << endl;
            input |= evaluateBitTable(baseInputs, connections[index][i], tableEvaluated, tableOutput) << i;
        }
        // cout << "inputs for node " << index << " is " << input << " aka: ";
        // for (int i = 0; i < connections[index].size(); i++)
        // cout << (input >> i & 1) << " ";
        // cout << endl;
        (*tableEvaluated)[index] = true;
        (*tableOutput)[index] = bitTables[index]->getTableBit(input);
        // cout << "solved: " << index << " is " << (*tableOutput)[index] << endl;
        return (*tableOutput)[index];
    }

    void mutate()
    {
        for (int i = 0; i < bitTables.size(); i++)
            bitTables[i]->mutate();
    }

    void print()
    {
        // cout << "linear: " << linear << endl;
        // cout << "inputLength: " << inputLength << endl;
        cout << "bitTables: " << endl;
        for (int i = 0; i < bitTables.size(); i++)
        {
            bitTables[i]->print();
            cout << endl;
        }
        // cout << "outputIndexes: ";
        // for (int i = 0; i < outputIndexes.size(); i++)
        //     cout << outputIndexes[i] << " ";
        // cout << endl;
        // cout << "connections: " << endl;
        // ;
        // for (int i = 0; i < connections.size(); i++)
        // {
        //     for (int j = 0; j < connections[i].size(); j++)
        //         cout << connections[i][j] << " ";
        //     cout << endl;
        // }
        // cout << endl;
    }
};