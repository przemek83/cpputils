#pragma once

#include <iostream>
#include <memory>

#include "cpputils/cpputils_global.h"

class StreamEaterImpl;

class CPPUTILS_API StreamEater
{
public:
    explicit StreamEater(std::ostream& stream);
    ~StreamEater();

    std::string getOutput() const;

private:
    std::unique_ptr<StreamEaterImpl> pImpl_;
};
