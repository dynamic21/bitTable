#pragma once
#include <chrono>

using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::seconds;
using std::chrono::steady_clock;
using std::chrono::system_clock;

steady_clock::time_point timer;

void startTimer()
{
    timer = steady_clock::now();
}

double stopTimer()
{
    return duration_cast<duration<double>>(steady_clock::now() - timer).count();
}