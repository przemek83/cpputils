#include "cpputils/Timer.h"

#include "cpputils/Logger.h"

template <typename T>
Timer<T>::Timer() : pImpl_(std::make_unique<Impl>())
{
}

template <typename T>
Timer<T>::~Timer()
{
    const std::chrono::time_point end{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> duration{end - pImpl_->start_};
    const auto executionTime{std::chrono::duration_cast<T>(duration).count()};
    Logger().logMsg("Execution time: " + std::to_string(executionTime) +
                    pImpl_->suffix_);
}

template <typename T>
Timer<T>::Impl::Impl()
    : start_(std::chrono::steady_clock::now()), suffix_(Timer<T>::getSuffix())
{
}

template <typename T>
Timer<T>::Impl::~Impl() = default;

template <typename T>
std::string Timer<T>::getSuffix()
{
    if (std::is_same_v<T, std::chrono::hours>)
        return "h";
    else if (std::is_same_v<T, std::chrono::minutes>)
        return "min";
    else if (std::is_same_v<T, std::chrono::seconds>)
        return "s";
    else if (std::is_same_v<T, std::chrono::milliseconds>)
        return "ms";
    else if (std::is_same_v<T, std::chrono::microseconds>)
        return "us";
    else
        return "ns";
}

// Explicit instantiation definitions
template class CPPUTILS_API Timer<std::chrono::microseconds>;
template class CPPUTILS_API Timer<std::chrono::milliseconds>;
template class CPPUTILS_API Timer<std::chrono::seconds>;
template class CPPUTILS_API Timer<std::chrono::minutes>;
template class CPPUTILS_API Timer<std::chrono::hours>;