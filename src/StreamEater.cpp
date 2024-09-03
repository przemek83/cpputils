#include "cpputils/StreamEater.h"

#include "StreamEaterImpl.h"

StreamEater::StreamEater(std::ostream& stream)
    : pImpl_(std::make_unique<StreamEaterImpl>(stream))
{
}

StreamEater::~StreamEater() = default;

std::string StreamEater::getOutput() const { return pImpl_->getOutput(); }
