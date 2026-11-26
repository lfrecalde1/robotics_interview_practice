#include <array>
#include <cstddef>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using Matrix = std::vector<std::vector<double>>;
void setColumn(Matrix &A, std::size_t column,
               const std::vector<double> &values) {

  if (values.size() != A.size()) {
    throw std::invalid_argument("Column length must equal the number of rows");
  }

  for (std::size_t row = 0; row < A.size(); ++row) {
    A.at(row).at(column) = values[row];
  }
}

class VectorOperations {
public:
  [[nodiscard]] double computeDot(const std::array<double, 2> &x,
                                  const std::array<double, 2> &y) const {

    double result = 0.0;

    for (std::size_t i = 0; i < x.size(); ++i) {
      result += x[i] * y[i];
    }

    return result;
  }

  [[nodiscard]] double computeDotAny(const std::vector<double> &x,
                                     const std::vector<double> &y) const {

    if (x.size() != y.size()) {
      throw std::invalid_argument(
          "computeDot: vectors must have the same size");
    }

    double result = 0.0;

    for (std::size_t i = 0; i < x.size(); ++i) {
      result += x[i] * y[i];
    }

    return result;
  }
};

class VectorOperationManual {
public:
  [[nodiscard]] double computeDot(const std::vector<double> &x,
                                  const std::vector<double> &y) const {

    double value = 0;

    if (x.size() != y.size()) {
      throw std::invalid_argument("The vector should be of the same size");
    }

    for (std::size_t i = 0; i < x.size(); i++) {
      value = value + x[i] * y[i];
    }

    return value;
  }
};
int main() {
  // call the class
  const VectorOperations operations;
  // This is  just vectors if n size
  std::cout << "Hello Fernando" << '\n';
  // With Array I need to define the size
  std::array<double, 2> point{1.0, 2.0};

  // With vector I do not need to define the size of the vector
  std::vector<double> commands{4, -1, 3};
  std::vector<double> states{4, -1, 3, 5};
  std::array<double, 5> point_five{1.0, 2.0};

  // Print point five
  std::cout << "point five: ";
  for (std::size_t i = 0; i < point_five.size(); ++i) {
    std::cout << point_five[i] << ' ';
  }
  std::cout << '\n';

  // Print point
  std::cout << "point: ";
  for (std::size_t i = 0; i < point.size(); i++) {
    std::cout << point[i] << ' ';
  }
  std::cout << '\n';

  // Print states
  std::cout << "States Vector: ";
  for (std::size_t i = 0; i < states.size(); i++) {

    std::cout << states[i] << " ";
  }
  std::cout << '\n';

  // matrices
  std::vector<std::vector<double>> points{{1.3, 2}, {3, 4.5}};
  // Three rows, four columns, initialized to zero.
  std::vector<std::vector<int>> grid(3, std::vector<int>(4, 0));

  std::cout << points[1][1] << '\n';
  std::cout << points[1][0] << '\n';

  // This is the way to create matrices
  const std::size_t rows = 2;
  const std::size_t cols = 2;
  std::vector<std::vector<double>> matrix(rows, std::vector<double>(cols, 0.0));
  std::vector<std::vector<double>> A(rows, std::vector<double>(cols, 0.0));

  matrix[0][0] = 1.4;
  matrix[1][1] = 2.4;

  for (std::size_t i = 0; i < matrix.size(); i++) {
    for (std::size_t j = 0; j < matrix[i].size(); j++) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }

  // verifyu dot product
  std::vector<double> x1{3.1, 5, 1};
  std::vector<double> x2{3.0, 5.1, 2.3};

  const double dot_x1x2 = operations.computeDotAny(x1, x2);
  std::cout << "Vector x1: ";
  for (std::size_t i = 0; i < x1.size(); i++) {
    std::cout << x1[i] << ' ';
  }
  std::cout << '\n';
  std::cout << "Vector x2: ";
  for (std::size_t i = 0; i < x2.size(); i++) {
    std::cout << x2[i] << ' ';
  }
  std::cout << '\n';

  std::cout << "Dot Product: ";
  std::cout << dot_x1x2 << '\n';

  // Creating my own function to compute operations
  const VectorOperationManual operationsmanual;
  const double dot = operationsmanual.computeDot(x1, x2);
  std::cout << "Dot Product: ";
  std::cout << dot << '\n';

  // Adding values to matrices
  Matrix B(2, std::vector<double>(3, 0.0));

  const std::vector<double> first_column{1.0, 2.0};
  const std::vector<double> second_column{3.0, 1.0};

  setColumn(B, 0, first_column);
  setColumn(B, 1, second_column);

  // Print matrix
  std::cout << "The matrix B is :" << '\n';
  for (std::size_t i = 0; i < B.size(); i++) {
    for (std::size_t j = 0; j < B[i].size(); j++) {
      std::cout << B[i][j] << ' ';
    }
    std::cout << '\n';
  }

  // create a vector
  std::vector<double> vector_x(5);
  std::cout << vector_x.size() << '\n';
}
