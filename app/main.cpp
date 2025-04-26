#include <iostream>
#include <limits>

#include "gm_lib.hpp"

int main()
{
    std::cout << "Hello world" << std::endl;
    MyClass my_obj{"This is an example"};
    my_obj.print_something();
    std::cout << std::endl;
}