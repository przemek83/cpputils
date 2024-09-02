#pragma once

#include <iostream>
#include <memory>

#include "cpputils/cpputils_global.h"

class CPPUTILS_API StreamEater
{
public:
    explicit StreamEater(std::ostream& stream);

    std::string getOutput() const;

private:
    class Impl;
    std::unique_ptr<Impl> pImpl_;
};
