#include "cpputils/Timer.h"
#include <chrono>

#include "TimerImpl.h"
#include "cpputils/Logger.h"

namespace
{
template <typename T>
long calculateTime(std::chrono::time_point<std::chrono::steady_clock> start)
{
    const std::chrono::time_point end{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> duration{end - start};
    auto executionTime{std::chrono::duration_cast<T>(duration).count()};

    return executionTime;
}
}  // namespace

Timer::Timer(Duration duration)
    : duration_{duration}, pImpl_(std::make_unique<TimerImpl>())
{
}

Timer::~Timer()
{
    const long executionTime{getExecutionTime()};
    Logger().logMsg("Execution time: " + std::to_string(executionTime) +
                    getSuffix(duration_));
}

std::string Timer::getSuffix(Duration duration)
{
    if (duration == Duration::HOURS)
        return "h";
    else if (duration == Duration::MINUTES)
        return "min";
    else if (duration == Duration::SECONDS)
        return "s";
    else if (duration == Duration::MILISECONDS)
        return "ms";
    else if (duration == Duration::MICROSECONDS)
        return "us";
    else
        return "ns";
}

long Timer::getExecutionTime() const
{
    const std::chrono::time_point start{pImpl_->getStart()};

    if (duration_ == Duration::HOURS)
        return calculateTime<std::chrono::hours>(start);
    else if (duration_ == Duration::MINUTES)
        return calculateTime<std::chrono::minutes>(start);
    else if (duration_ == Duration::SECONDS)
        return calculateTime<std::chrono::seconds>(start);
    else if (duration_ == Duration::MILISECONDS)
        return calculateTime<std::chrono::milliseconds>(start);
    else if (duration_ == Duration::MICROSECONDS)
        return calculateTime<std::chrono::microseconds>(start);
    else
        return calculateTime<std::chrono::nanoseconds>(start);
}
