#include <iostream>
#include "include/wrapped_uint.hpp"
#include "include/wuintvariant_varlist.hpp"

using namespace experimentsWithVariant;

int main() {
  wuintvariant_varlist varList{};
  varList.create_variable("A",10,17);
  std::cout << varList.to_string("A") << std::endl;
  return 0;
}
