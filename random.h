#pragma once
#include <random>
#include "chrono.h"

using std::mt19937;
using std::random_device;

random_device rd;
mt19937 gen = mt19937(rd() ^ 
((mt19937::result_type)duration_cast<seconds>(system_clock::now().time_since_epoch()).count() +
(mt19937::result_type)duration_cast<std::chrono::microseconds>(high_resolution_clock::now().time_since_epoch()).count()));

size_t random(int max = 2, int min = 0) // exclusive ex: (1 - 0)
{
    mt19937::result_type n;
    int range = (max - min);
    while ((n = gen()) > mt19937::max() - (mt19937::max() - range + 1) % range)
        ;
    return n % range + min;
}