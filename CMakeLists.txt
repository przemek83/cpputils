cmake_minimum_required(VERSION 3.14)

project(cpputils
        LANGUAGES CXX
        VERSION 1.0.0
        DESCRIPTION "C++ utility classes."
        HOMEPAGE_URL "https://github.com/przemek83/cpputils")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(CODE_COVERAGE "Collect coverage" OFF)

if(CODE_COVERAGE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 --coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 --coverage")
endif()

include(GNUInstallDirs)

set(${PROJECT_NAME}_SOURCES
    src/cpputils_global.h
    src/StreamEater.cpp
    src/StreamEater.h
    src/Logger.h
    src/Timer.h
)

set(PUBLIC_HEADERS
    src/cpputils_global.h
    src/StreamEater.h
    src/Logger.h
    src/Timer.h
)

add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER "${PUBLIC_HEADERS}")

configure_file(${PROJECT_NAME}.pc.in ${PROJECT_NAME}.pc @ONLY)

target_include_directories(${PROJECT_NAME} PRIVATE .)

target_compile_definitions(${PROJECT_NAME} PRIVATE CPPUTILS_LIBRARY)

install(TARGETS ${PROJECT_NAME} 
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
