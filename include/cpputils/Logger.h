#pragma once

#include <string>

#include "cpputils/cpputils_global.h"

class CPPUTILS_API Logger
{
public:
    void info(const std::string& msg) const;
    void error(const std::string& msg) const;
};

Logger log();