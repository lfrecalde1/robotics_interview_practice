#include <algorithm>
#include <iostream>
#include <vector>

void printint(const std::vector<int> &x) {
  int n = static_cast<int>(x.size());
  std::cout << "Verify the data of the vecto :" << '\n';
  for (int i = 0; i < n; i++) {
    std::cout << x[i] << ' ';
  }
  std::cout << '\n';
}

class Solution {
public:
  [[nodiscard]] std::vector<int> plusOne(std::vector<int> &digits) const {
    int n = static_cast<int>(digits.size()) - 1;
    std::vector<int> data;
    int value = 0;
    int carry = 1;

    std::cout << "accessc data inverse" << '\n';
    for (int i = n; i >= 0; i--) {
      value = digits[i] + carry;
      std::cout << value << ' ';
      data.push_back(value % 10);
      carry = value / 10;
    }
    std::cout << '\n';
    printint(data);
    if (carry > 0) {
      data.push_back(carry);
    }
    std::reverse(data.begin(), data.end());
    printint(data);
    return data;
  }
};

int main() {
  std::cout << "Plusone Problem" << '\n';
  const Solution plusOneSolution;
  // Specify the vector
  std::vector<int> vector = {5, 6, 9, 9, 1, 9};

  printint(vector);
  auto b = plusOneSolution.plusOne(vector);
  return 0;
}
