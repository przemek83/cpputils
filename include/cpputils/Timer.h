#pragma once

#include <chrono>
#include <memory>
#include <string>

#include "cpputils/Logger.h"
#include "cpputils/cpputils_global.h"

template <typename T>
class CPPUTILS_API Timer
{
public:
    Timer();
    ~Timer();

private:
    class Impl;
    std::unique_ptr<Impl> pImpl_;
    std::string getSuffix() const;
};

template <typename T>
class CPPUTILS_API Timer<T>::Impl
{
public:
    Impl();
    ~Impl();

    std::chrono::time_point<std::chrono::steady_clock> start_{
        std::chrono::steady_clock::now()};
    std::string suffix_;
};

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
Timer<T>::Impl::Impl() : suffix_(Timer<T>().getSuffix())
{
}

template <typename T>
Timer<T>::Impl::~Impl() = default;

template <typename T>
std::string Timer<T>::getSuffix() const
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
