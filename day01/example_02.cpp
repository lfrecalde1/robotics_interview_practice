#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdlib>
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

[[nodiscard]] std::vector<double> getColumn(const Matrix &A,
                                            std::size_t column) {

  std::vector<double> values(A.size());

  for (std::size_t row = 0; row < A.size(); ++row) {
    values[row] = A.at(row).at(column);
  }

  return values;
}

[[nodiscard]] double computeChebyshev(const std::vector<double> &x,
                                      const std::vector<double> &y) {
  if (x.size() != y.size()) {
    throw std::invalid_argument("The vector should be of the same size");
  }

  std::vector<double> sum(x.size());

  for (std::size_t i = 0; i < x.size(); ++i) {
    sum[i] = std::abs(x[i] - y[i]);
  }

  const auto max = std::max_element(sum.begin(), sum.end());
  return *max;
}

[[nodiscard]] double minimumPath(Matrix &A) {

  std::size_t columns = A[0].size();
  double total_distance = 0.0;
  for (std::size_t col = 0; col + 1 < columns; ++col) {
    const std::vector<double> first = getColumn(A, col);
    const std::vector<double> second = getColumn(A, col + 1);

    total_distance += computeChebyshev(first, second);
  }

  return total_distance;
}

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

  // verifyu dot product
  std::vector<double> x1{3.1, 5, 1};
  std::vector<double> x2{3.0, 5.1, 2.3};

  // Creating my own function to compute operations
  const VectorOperationManual operationsmanual;
  const double dot = operationsmanual.computeDot(x1, x2);
  std::cout << "Dot Product: ";
  std::cout << dot << '\n';

  // Adding values to matrices
  Matrix B(2, std::vector<double>(3, 0.0));

  const std::vector<double> first_column{1.0, 1.0};
  const std::vector<double> second_column{3.0, 4.0};
  const std::vector<double> third_column{-1.0, 0.0};

  setColumn(B, 0, first_column);
  setColumn(B, 1, second_column);
  setColumn(B, 2, third_column);

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

  // Checkling vectors and sum
  std::cout << "Vector a :";
  for (std::size_t i = 0; i < first_column.size(); i++) {
    std::cout << first_column[i] << " ";
  }
  std::cout << '\n';

  std::cout << "Vector b :";
  for (std::size_t i = 0; i < second_column.size(); i++) {
    std::cout << second_column[i] << " ";
  }
  std::cout << '\n';
  // compute the Chebyshev distance
  const double distance = computeChebyshev(first_column, second_column);
  std::cout << "Chebyshev distance: " << distance << '\n';

  double total_distance = minimumPath(B);
  std::cout << "Minimum path: " << total_distance << '\n';

  // compute the Chebyshev distance
  // auto max_it = std::max_element(first_column.begin(), second_column.end());
}
