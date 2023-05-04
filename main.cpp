#include <iostream>
#include "include/wrapped_uint.hpp"
#include "include/wuintvariant_varlist.hpp"
using namespace experiments_with_variant;

int main() {
    wuintvariant_varlist varList{};
    varList.create_variable("A",10,17);
    std::cout << std::get<10>(varList.get_variable("A")) << std::endl;
    return 0;
}
