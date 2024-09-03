#include <stdlib.h>
#include <iostream>

#include <cpputils/Logger.h>
#include <cpputils/StreamEater.h>
#include <cpputils/Timer.h>

namespace
{
std::string eatingExample()
{
    const StreamEater eater(std::cout);
    std::cout << "To be eaten!\n";
    return eater.getOutput();
}
}  // namespace

int main(int argc, char* argv[])
{
    const Timer timer{Timer::Duration::MICROSECONDS};

    log().info("My message");

    const std::string eaten{eatingExample()};
    std::cout << "Eaten: " << eaten;

    return EXIT_SUCCESS;
}