#pragma once

#include <string>

#include "cpputils/cpputils_global.h"

class CPPUTILS_API Logger
{
public:
    void logMsg(const std::string& message) const;
    void logErr(const std::string& errorMessage) const;
};
