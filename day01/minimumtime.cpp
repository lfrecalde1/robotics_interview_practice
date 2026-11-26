#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

class Solution {
public:
  [[nodiscard]] int
  minTimeToVisitAllPoints(const std::vector<std::vector<int>> &x) const {

    int time = 0;

    if (x.size() == 1) {
      return 0;
    }
    for (std::size_t i = 0; i < x.size() - 1; i++) {
      time = time + std::max(std::abs(x[i + 1][0] - x[i][0]),
                             std::abs(x[i + 1][1] - x[i][1]));
    }
    return time;
  }
};
int main() {
  std::cout << "Solving the minimum time problem" << '\n';

  // Verify the proper norm
  std::vector<std::vector<int>> input{{1, 1}, {3, 4}, {-1, 0}};

  const Solution solutionMinimum;
  int time = solutionMinimum.minTimeToVisitAllPoints(input);
  std::cout << time << '\n';
  return 0;
}
