#include "TimerImpl.h"

std::chrono::time_point<std::chrono::steady_clock> TimerImpl::getStart() const
{
    return start_;
}