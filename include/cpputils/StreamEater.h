#pragma once

#include <iostream>
#include <memory>

#include "cpputils/cpputils_global.h"

class CPPUTILS_API StreamEater
{
public:
    explicit StreamEater(std::ostream& stream);
    ~StreamEater();

    std::string getOutput() const;

private:
    class CPPUTILS_API Impl;
    std::unique_ptr<Impl> pImpl_;
};
