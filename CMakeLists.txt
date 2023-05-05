cmake_minimum_required(VERSION 3.26)
project(ExperimentsWithVariant)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

add_executable(ExperimentsWithVariant
        include/variant_type.hpp
        include/wrapped_uint.hpp
        include/wuintvariant_varlist.hpp
        src/wuintvariant_varlist.cpp
        main.cpp)
