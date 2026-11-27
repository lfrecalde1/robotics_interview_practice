#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
class Solution {
public:
  [[nodiscard]] float findMedianSortedArrays(std::vector<int> &x,
                                             std::vector<int> &y) const {
    // variables
    int n = 0;
    double median = 0.0;

    for (std::size_t i = 0; i < y.size(); i++) {
      x.push_back(y[i]);
    }

    std::sort(x.begin(), x.end());
    std::cout << "Check the full vector :" << '\n';
    for (std::size_t i = 0; i < x.size(); i++) {
      std::cout << x[i] << ' ';
    }
    std::cout << '\n';

    n = x.size();

    if (n % 2 == 1) {
      // std::cout << n % 2 << '\n';
      median = x[n / 2];
      return median;

    }

    else {
      // std::cout << n % 2 << '\n';
      double value_a = 0;
      double value_b = 0;
      value_a = x[n / 2];
      value_b = x[(n / 2) - 1];
      // std::cout << value_a << '\n';
      // std::cout << value_b << '\n';
      median = (value_a + value_b) / 2;
      return median;
    }
  }
};
int main() {

  std::cout << "This Program compute only the median of two ordered vector"
            << '\n';

  const Solution solutionMedian;
  // Create the vectors
  std::vector<int> x{1, 6};
  std::vector<int> y{22, 6, 3, 5};

  std::sort(x.begin(), x.end());
  std::sort(y.begin(), y.end());

  double median;
  median = solutionMedian.findMedianSortedArrays(x, y);
  std::cout << "The median is: " << '\n';
  std::cout << median << '\n';
  return 0;
}
