#include "StreamEaterImpl.h"

#include "StreamEaterImpl.h"

StreamEaterImpl::StreamEaterImpl(std::ostream& stream)
    : stream_{stream}, stdBuffer_{stream.rdbuf()}
{
    stream_.rdbuf(fakeOutput_.rdbuf());
}

StreamEaterImpl::~StreamEaterImpl() { stream_.rdbuf(stdBuffer_); }

std::string StreamEaterImpl::getOutput() const { return fakeOutput_.str(); }