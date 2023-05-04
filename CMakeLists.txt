cmake_minimum_required(VERSION 3.26)
project(ExperimentsWithVariant)

set(CMAKE_CXX_STANDARD 23)

add_executable(ExperimentsWithVariant main.cpp include/wrapped_uint.hpp include/variant_type.hpp src/wuintvariant_varlist.cpp include/wuintvariant_varlist.hpp)
