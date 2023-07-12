#include <iostream>
#include <limits>

#include "gm_lib.hpp"

int main()
{
    std::cout << "Execution will start... Press Enter to exit" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl;
}
