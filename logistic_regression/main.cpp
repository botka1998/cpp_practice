#include <iostream>
#include <random>
#include <gmtl/gmtl.h>

using std::cout;
using std::endl;

// def sigmoid(z):
//     s = 1 / (1 + np.exp(-z))

//     return s
template <typename T, unsigned int Rows, unsigned int Cols>
gmtl::Matrix<T, Rows, Cols> sigmoid(gmtl::Matrix<T, Rows, Cols> &z)
{
    for (int row = 0; row < z.Rows; row++)
    {
        for (int col = 0; col < z.Cols; col++)
        {
            z(row, col) = 1 / (1 + std::exp(-z(row, col)));
        }
    }
    return z;
}

int main()
{
    gmtl::Matrix<float, 10, 10> my_matrix;

    gmtl::mult<float, 10, 10>(my_matrix, 0.1);

    sigmoid(my_matrix);
    cout << my_matrix;
    return 1;
}