#pragma once

#include <chrono>

class TimerImpl
{
public:
    std::chrono::time_point<std::chrono::steady_clock> getStart() const;

private:
    std::chrono::time_point<std::chrono::steady_clock> start_{
        std::chrono::steady_clock::now()};
};