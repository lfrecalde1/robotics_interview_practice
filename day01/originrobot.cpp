#include <array>
#include <iostream>
class Solution {
public:
  [[nodiscard]] const bool judgecircle(const std::string &moves) const {

    int x = 0;
    int y = 0;

    for (std::size_t i = 0; i < moves.size(); i++) {
      if (moves[i] == 'R') {
        x = x + 1;
      }
      if (moves[i] == 'L') {
        x = x - 1;
      }
      if (moves[i] == 'U') {
        y = y + 1;
      }
      if (moves[i] == 'D') {
        y = y - 1;
      }
    }

    return x == 0 & y == 0;
  }
};

int main() {
  std::string moves = "UD";
  std::cout << "Verify entries" << '\n';
  for (std::size_t i = 0; i < moves.size(); i++) {
    std::cout << moves[i] << ' ';
  }
  std::cout << '\n';

  // Verify the class
  const Solution solution_verify;
  const bool validation = solution_verify.judgecircle(moves);
  std::cout << validation << '\n';
  return 0;
}
