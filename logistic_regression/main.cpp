#include <iostream>
#include <random>
#include <gmtl/gmtl.h>

using std::cout;
using std::endl;

// def sigmoid(z):
//     s = 1 / (1 + np.exp(-z))

//     return s
gmtl::Matrix<float, 10, 10> sigmoid(gmtl::Matrix<float, 10, 10> z)
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

    my_matrix = sigmoid(my_matrix);
    cout << my_matrix;
    return 1;
}