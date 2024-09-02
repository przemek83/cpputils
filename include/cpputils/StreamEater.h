#pragma once

#include <iostream>
#include <sstream>

#include "cpputils/cpputils_global.h"

class CPPUTILS_API StreamEater
{
public:
    explicit StreamEater(std::ostream& stream);
    ~StreamEater();

    std::string getOutput() const;

private:
    std::ostream& stream_;

    std::streambuf* stdBuffer_{stream_.rdbuf()};
    std::ostringstream fakeOutput_;
};
