#include <stdlib.h>
#include <iostream>

#include "cpputils/Logger.h"
#include "cpputils/StreamEater.h"
#include "cpputils/Timer.h"

int main(int argc, char* argv[])
{
    Timer<std::chrono::microseconds> timer;

    Logger().logMsg("My message");

    std::string eaten;
    {
        StreamEater eater(std::cout);
        std::cout << "To be eaten!\n";
        eaten = eater.getOutput();
    }
    std::cout << "Eaten: " << eaten;

    return EXIT_SUCCESS;
}