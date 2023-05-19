#include <iostream>
#include "cat.h"
using std::cout;
using std::endl;
int main()
{
    auto c = animals::MiniCat();
    c.meow();
    return 0;
}