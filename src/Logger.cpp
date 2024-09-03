
#include "cpputils/Logger.h"

#include <iostream>

void Logger::info(const std::string& msg) const
{
    std::cout << msg << "\n";
    std::cout.flush();
}

void Logger::error(const std::string& msg) const
{
    std::cerr << msg << "\n";
    std::cerr.flush();
}
