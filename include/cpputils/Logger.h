#pragma once

#include <string>

#include "cpputils/dll.h"

class CPPUTILS_API Logger
{
public:
    void info(const std::string& msg) const;
    void error(const std::string& msg) const;
};

Logger log();