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
    /*
    Compute the sigmoid of z

    Arguments : z-- A Matrix of any size.

        Return : s-- sigmoid(z)
    */
    gmtl::Matrix<T, Rows, Cols> resultMatrix;

    for (int row = 0; row < z.Rows; row++)
    {
        for (int col = 0; col < z.Cols; col++)
        {
            resultMatrix(row, col) = 1 / (1 + std::exp(-z(row, col)));
        }
    }
    return resultMatrix;
}

// def initialize_with_zeros(dim):
//     """
//     This function creates a vector of zeros of shape (dim, 1) for w and initializes b to 0.

//     Argument:
//     dim -- size of the w vector we want (or number of parameters in this case)

//     Returns:
//     w -- initialized vector of shape (dim, 1)
//     b -- initialized scalar (corresponds to the bias) of type float
//     """
//     # YOUR CODE STARTS HERE
//     w = np.zeros((dim, 1))
//     b = 0.0

//     # YOUR CODE ENDS HERE

//     return w, b

int main()
{
    gmtl::Matrix<float, 10, 10> my_matrix;

    gmtl::mult<float, 10, 10>(my_matrix, 0.1);

    my_matrix = sigmoid(my_matrix);
    cout << my_matrix;
    return 1;
}