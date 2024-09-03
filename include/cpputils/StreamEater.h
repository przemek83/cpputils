#pragma once

#include <iostream>
#include <memory>

#include "cpputils/dll.h"

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
