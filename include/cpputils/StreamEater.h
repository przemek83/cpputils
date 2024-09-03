#pragma once

#include <iostream>
#include <memory>

#include "cpputils/cpputils_global.h"

class StreamEaterImpl;

class StreamEater
{
public:
    CPPUTILS_API explicit StreamEater(std::ostream& stream);
    CPPUTILS_API ~StreamEater();

    std::string getOutput() const;

private:
    std::unique_ptr<StreamEaterImpl> pImpl_;
};
