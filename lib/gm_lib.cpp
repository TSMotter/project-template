#include "gm_lib.hpp"

void MyClass::print_something(void)
{
    std::cout << "This is m_val: " << m_val << std::endl;
    std::cout << "This is SCALE: " << SCALE << std::endl;
    std::cout << "This is LIB1_VERSION_MAJOR: " << LIB1_VERSION_MAJOR << std::endl;
    std::cout << "This is LIB1_VERSION_MINOR: " << LIB1_VERSION_MINOR << std::endl;
    std::cout << "This is LIB1_VERSION_PATCH: " << LIB1_VERSION_PATCH << std::endl;
}
