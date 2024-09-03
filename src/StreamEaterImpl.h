#pragma once

#include <ostream>
#include <sstream>

class StreamEaterImpl
{
public:
    explicit StreamEaterImpl(std::ostream& stream);

    ~StreamEaterImpl();

    std::string getOutput() const;

private:
    std::ostream& stream_;
    std::streambuf* stdBuffer_;
    std::ostringstream fakeOutput_;
};