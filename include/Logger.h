#pragma once

#include <iostream>

#include "cpputils_global.h"

class CPPUTILS_API Logger
{
public:
    void logMsg(const std::string& message) const
    {
        std::cout << message << "\n";
        std::cout.flush();
    }

    void logErr(const std::string& errorMessage) const
    {
        std::cerr << errorMessage << "\n";
        std::cerr.flush();
    }
};
