#pragma once

#include <memory>
#include <string>

#include "cpputils/cpputils_global.h"

class TimerImpl;

class Timer
{
public:
    enum class Duration
    {
        HOURS,
        MINUTES,
        SECONDS,
        MILISECONDS,
        MICROSECONDS,
        NANOSECONDS
    };

    CPPUTILS_API explicit Timer(Duration duration);
    CPPUTILS_API ~Timer();

private:
    static std::string getSuffix(Duration duration);

    long getExecutionTime() const;

    Duration duration_;

    std::unique_ptr<TimerImpl> pImpl_;
};
