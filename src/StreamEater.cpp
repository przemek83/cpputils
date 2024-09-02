#include "cpputils/StreamEater.h"

StreamEater::StreamEater(std::ostream& stream) : stream_(stream)
{
    stream_.rdbuf(fakeOutput_.rdbuf());
}

StreamEater::~StreamEater() { stream_.rdbuf(stdBuffer_); }

std::string StreamEater::getOutput() const { return fakeOutput_.str(); }
