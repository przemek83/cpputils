#pragma once

#include <chrono>
#include <memory>
#include <string>

#include "cpputils/cpputils_global.h"

template <typename T>
class Timer
{
public:
    CPPUTILS_API Timer();
    CPPUTILS_API ~Timer();

private:
    static std::string getSuffix();

    class Impl;
    std::unique_ptr<Impl> pImpl_;
};

template <typename T>
class Timer<T>::Impl
{
public:
    Impl();
    ~Impl();

    std::chrono::time_point<std::chrono::steady_clock> start_;
    std::string suffix_;
};

// Explicit instantiation declarations
extern template class CPPUTILS_API Timer<std::chrono::microseconds>;
extern template class CPPUTILS_API Timer<std::chrono::milliseconds>;
extern template class CPPUTILS_API Timer<std::chrono::seconds>;
extern template class CPPUTILS_API Timer<std::chrono::minutes>;
extern template class CPPUTILS_API Timer<std::chrono::hours>;