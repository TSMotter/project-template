#ifndef __GM_LIB__
#define __GM_LIB__

#include <iostream>
#include <string>

#include "lib1.hpp"

#define SCALE 50
#define BUFF_SIZE (2 * SCALE)

class MyClass
{
   public:
    MyClass(const char *val) : m_val{val}
    {
    }
    ~MyClass()
    {
    }

    void print_something(void);

   private:
    std::string m_val;
};

#endif