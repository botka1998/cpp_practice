#include <iostream>
#include <gmtl/gmtl.h>

using std::cout;
using std::endl;

int main()
{
    gmtl::Matrix<float, 10, 10> my_matrix;
    cout << my_matrix;
    return 1;
}