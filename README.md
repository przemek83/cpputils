# About

Library `cpputils` is a collection of utility classes designed to simplify common tasks in C++ development. The library includes classes for logging, stream manipulation and timing.

# Features
- **Logger**: A simple logging class to output messages to the console.
- **StreamEater**: A class to capture and manipulate stream output.
- **Timer**: A class to measure execution time in various time units.

# Building
Clone and use CMake directly or via any IDE supporting it. CMake **should**:
+ configure everything automatically,
+ compile and create binaries.

As a result of compilation, library binary and binary with examples should be created. Library can be used as a shared or static one. For shared library use on Windows, define `CPPUTILS_SHARED_LIB`. Check `include/cpputils/dll.h` for more details.

## Used tools
| Tool |  Windows | Ubuntu |
| --- | --- | --- |
| OS version | 10 22H2 | 24.04 |
| GCC | 13.1.0 | 13.2.0 |
| CMake | 3.30.2 | 3.28.3 |
| Git | 2.46.0 | 2.43.0 |

# Usage
One of the ways is to include in project file `CMakeLists.txt.cpputils` containing:
```
include(FetchContent)

FetchContent_Declare(
    cpputils
    GIT_REPOSITORY https://github.com/przemek83/cpputils.git
    GIT_TAG <tag/branch>
)

FetchContent_MakeAvailable(cpputils)
```
and adding in `CMakeLists.txt`:
```
include(CMakeLists.txt.cpputils)
```
From this point onwards, it should be possible to use `cpputils` as a link library:
```
target_link_libraries(${PROJECT_NAME} cpputils)
```
Check the `examples` subproject and my other project named `data-explorer` for usage examples.

## Logger

```cpp
#include <cpputils/Logger.h>
...
Logger logger;
logger.info("This is a log message.");
logger.error("This is error message.");

Log().info("This is short form.");
```
Result:
```
This is a log message.
This is error message.
This is short form.
```
## StreamEater

```cpp
#include <cpputils/StreamEater.h>
...
std::string eaten;
{
    const StreamEater eater(std::cout);
    std::cout << "This will be captured." << std::endl;
    eaten = eater.getOutput();
}
std::cout << "Captured output: " << eaten << std::endl;
```
Result:
```
Captured output: This will be captured.
```
## Timer

```cpp
#include <cpputils/Timer.h>
...
{
    Timer timer{Timer::Duration::MILISECONDS};
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
```
Result:
```
Execution time: 1000ms
```

# License
This project is licensed under the MIT License. See the LICENSE file for details.