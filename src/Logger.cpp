
#include "cpputils/Logger.h"

#include <iostream>

void Logger::logMsg(const std::string& message) const
{
    std::cout << message << "\n";
    std::cout.flush();
}

void Logger::logErr(const std::string& errorMessage) const
{
    std::cerr << errorMessage << "\n";
    std::cerr.flush();
}
