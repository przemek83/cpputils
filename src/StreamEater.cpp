#include "cpputils/StreamEater.h"

#include <sstream>

class StreamEater::Impl
{
public:
    explicit Impl(std::ostream& stream)
        : stream_{stream}, stdBuffer_{stream.rdbuf()}
    {
        stream_.rdbuf(fakeOutput_.rdbuf());
    }

    ~Impl()
    {
        stream_.rdbuf(stdBuffer_);
    }

    std::string getOutput() const
    {
        return fakeOutput_.str();
    }

private:
    std::ostream& stream_;
    std::streambuf* stdBuffer_;
    std::ostringstream fakeOutput_;
};

StreamEater::StreamEater(std::ostream& stream) : pImpl_(std::make_unique<Impl>(stream))
{
}

std::string StreamEater::getOutput() const { return pImpl_->getOutput(); }
