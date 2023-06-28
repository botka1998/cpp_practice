#include <iostream>
#include <random>
#include <gmtl/gmtl.h>

using std::cout;
using std::endl;

float generateRandomFloat()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0f, 1.0f);
    return dis(gen);
}
template <typename T, unsigned int Rows, unsigned int Cols>
gmtl::Matrix<T, Rows, Cols> fillMatrixRandom(gmtl::Matrix<T, Rows, Cols> &in_matrix)
{
    for (int row = 0; row < in_matrix.Rows; row++)
    {
        for (int col = 0; col < in_matrix.Cols; col++)
        {
            in_matrix(row, col) = generateRandomFloat();
        }
    }

    return in_matrix;
}
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

// def propagate(w, b, X, Y):
//     """
//     Implement the cost function and its gradient for the propagation explained above

//     Arguments:
//     w -- weights, a numpy array of size (num_px * num_px * 3, 1)
//     b -- bias, a scalar
//     X -- data of size (num_px * num_px * 3, number of examples)
//     Y -- true "label" vector (containing 0 if non-cat, 1 if cat) of size (1, number of examples)

//     Return:
//     grads -- dictionary containing the gradients of the weights and bias
//             (dw -- gradient of the loss with respect to w, thus same shape as w)
//             (db -- gradient of the loss with respect to b, thus same shape as b)
//     cost -- negative log-likelihood cost for logistic regression

//     Tips:
//     - Write your code step by step for the propagation. np.log(), np.dot()
//     """

//     m = X.shape[1]

//     # FORWARD PROPAGATION (FROM X TO COST)
//     #(≈ 2 lines of code)
//     # compute activation
//     # A = ...
//     # compute cost by using np.dot to perform multiplication.
//     # And don't use loops for the sum.
//     # cost = ...
//     # YOUR CODE STARTS HERE
//     A = sigmoid(np.dot(w.T, X) + b)
//     cost = -(np.sum(Y * np.log(A) + (1 - Y) * np.log(1 - A)) )/m
//     # YOUR CODE ENDS HERE

//     # BACKWARD PROPAGATION (TO FIND GRAD)
//     #(≈ 2 lines of code)
//     # dw = ...
//     # db = ...
//     # YOUR CODE STARTS HERE
//     dw = np.dot(X, (A-Y).T)/m
//     db = np.sum(A-Y)/m

//     # YOUR CODE ENDS HERE
//     cost = np.squeeze(np.array(cost))

//     grads = {"dw": dw,
//              "db": db}

//     return grads, cost
template <typename T, unsigned int Rows, unsigned int Cols>
// float calculate_cost(gmtl::Matrix<T, Rows, Cols> &w, gmtl::Matrix<T, Rows, Cols> &b, gmtl::Matrix<T, Rows, Cols> &X, gmtl::Matrix<T, Rows, Cols> &Y)
float calculateCost(gmtl::Matrix<T, Rows, Cols> &Y, gmtl::Matrix<T, Rows, Cols> &A)
{
    float sum = 0;
    const unsigned int m = Y.Cols;
    for (unsigned int i = 0; i < m; i++)
    {
        sum += Y(0, i) * std::log(A(0, i)) + (1 - Y(0, i)) * std::log(1 - A(0, i));
    }
    return -sum / m;
}
int main()
{
    gmtl::Matrix<float, 10, 10> my_matrix;
    gmtl::Matrix<float, 1, 10> Y;
    gmtl::Matrix<float, 1, 10> A;
    fillMatrixRandom(Y);
    fillMatrixRandom(A);

    gmtl::mult<float, 10, 10>(my_matrix, 0.1);

    my_matrix = sigmoid(my_matrix);
    cout << calculateCost(Y, A);
    return 1;
}