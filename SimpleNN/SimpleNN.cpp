// SimpleNN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

class NN
{
public:
    NN(int inputs) : 
        params(inputs)
    {
        srand(time(0));

        for (int i = 0; i < inputs; ++i)
        {
            params[i] = static_cast<double>(rand() / RAND_MAX);
        }
    }

    ~NN();

    double forward(vector<double> args)
    {
        double res = 0.0;

        for (int i = 0; i < args.size(); ++i)
        {
            res += args[i] * params[i];

        }

        return 0 > res ? 0 : res;
    }



private:
    vector<double> params;
};


int main()
{

    vector< vector<NN*> > net = {
        {new NN(1), new NN(1)},
        { new NN(2), new NN(2), new NN(2)},
        {new NN(3)}
    };




    return 0;
}

