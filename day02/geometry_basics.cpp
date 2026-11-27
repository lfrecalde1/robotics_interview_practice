#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

class geometryOperations {
public:
  [[nodiscard]] double dotProduc(const std::vector<double> &x,
                                 const std::vector<double> &y) const {
    int n = static_cast<int>(x.size());
    if (x.size() != y.size()) {
      throw std::invalid_argument(
          "The vectors do no have the same number of elemens");
    }
    double dot = 0;
    for (int i = 0; i < n; i++)

    {
      dot = dot + x[i] * y[i];
    }
    return dot;
  }
};

int main()

{
  std::cout << "Geometry beasics operations" << '\n';
  // Create class geometric operations
  const geometryOperations Operations;

  // Create vector for geometry operations
  std::vector<double> vector_a{1.2, 5.0, 4};
  std::vector<double> vector_b{11.2, 15.0, 6};

  double dot = Operations.dotProduc(vector_a, vector_b);
  std::cout << "The dot prodcut is :" << '\n';
  std::cout << dot << '\n';
  return 0;
}
