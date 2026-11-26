#include <array>
#include <iostream>
#include <string>
#include <vector>
void print(const std::vector<double> &x) {
  std::cout << "Verify the variable :";
  for (std::size_t i = 0; i < x.size(); i++) {
    std::cout << x[i] << ' ';
  }
  std::cout << '\n';
}

int main() {
  std::cout << "Verify Basic Construction" << '\n';

  // This is a std::string
  std::string sentece = "RULD";
  std::cout << "Verify the sentence string :";
  std::cout << '\n';

  for (std::size_t i = 0; i < sentece.size(); i++) {

    std::cout << "Index: " << i;
    std::cout << " Values: " << sentece[i] << '\n';
  }
  std::cout << '\n';

  // This is an array
  std::array<double, 5> vector{1.0, 2.0};
  std::cout << "Verify the array :";
  for (std::size_t i = 0; i < vector.size(); i++) {

    std::cout << vector[i] << ' ';
  }
  std::cout << '\n';

  // This is a vector
  std::vector<double> state(2);
  std::vector<double> state_1{1.2, 3.4, 7.9};

  state[0] = 4.0;
  std::cout << "Verify the vector 1:";
  for (std::size_t i = 0; i < state_1.size(); i++) {

    std::cout << state_1[i] << ' ';
  }
  std::cout << "the size of the vector 1 is : " << state_1.size();
  std::cout << '\n';

  std::cout << "Verify the vector :";
  for (std::size_t i = 0; i < state.size(); i++) {

    std::cout << state[i] << ' ';
  }
  std::cout << "the size of the vector is : " << state.size();
  std::cout << '\n';

  // verify Vectors(3) {3}
  std::vector<double> control(3); // this creates directly the vector of 1x3
  std::vector<double> control_1{
      3}; // this created the vector of 1x1 with 3 inside
  std::vector<double> control_2;

  std::cout << "the size of the control is : " << control.size();
  std::cout << '\n';
  std::cout << "the size of the control_1 is : " << control_1.size();
  std::cout << '\n';
  std::cout << "the size of the control_2 is : " << control_2.size();
  std::cout << '\n';

  std::cout << "Verify the Control :";
  for (std::size_t i = 0; i < control.size(); i++) {

    std::cout << control[i] << ' ';
  }
  std::cout << '\n';

  std::cout << "Verify the Control_1 :";
  for (std::size_t i = 0; i < control_1.size(); i++) {

    std::cout << control_1[i] << ' ';
  }
  std::cout << '\n';

  // using reserve for vectors to see the behavior
  std::vector<double> vector_aux;
  std::cout << "the size of the vector_aux is : " << vector_aux.size();
  std::cout << '\n';
  std::cout << "the capacity of the vector_aux is : " << vector_aux.capacity();
  std::cout << '\n';

  // vector_aux.reserve(5);
  std::cout << "the size of the vector_aux is : " << vector_aux.size();
  std::cout << '\n';
  std::cout << "the capacity of the vector_aux is : " << vector_aux.capacity();
  std::cout << '\n';

  vector_aux.push_back(20.0);
  std::cout << "the size of the vector_aux is : " << vector_aux.size();
  std::cout << '\n';
  std::cout << "the capacity of the vector_aux is : " << vector_aux.capacity();
  std::cout << '\n';

  vector_aux.push_back(30.0);
  std::cout << "the size of the vector_aux is : " << vector_aux.size();
  std::cout << '\n';
  std::cout << "the capacity of the vector_aux is : " << vector_aux.capacity();
  std::cout << '\n';

  std::cout << "Verify the Control_1 :";
  for (std::size_t i = 0; i < vector_aux.size(); i++) {

    std::cout << vector_aux[i] << ' ';
  }
  std::cout << '\n';

  // This section is for nested vectors
  std::vector<std::vector<double>> points{{1.3, 2.3}, {3, 4.5}, {50.9, 3.0}};
  // Three rows, four columns, initialized to zero.
  std::vector<double> variable(2, 3);
  std::vector<std::vector<int>> grid(3, std::vector<int>(4, 0));

  std::cout << "Verify the variable :";
  for (std::size_t i = 0; i < variable.size(); i++) {

    std::cout << variable[i] << ' ';
  }
  std::cout << '\n';

  // verify the size of points
  std::cout << "Verify the size of the matrix points :";
  std::cout << '\n';

  for (std::size_t i = 0; i < points.size(); i++) {
    std::cout << "the size of the row: " << i << " is " << points[i].size()
              << '\n';
    for (std::size_t j = 0; j < points[i].size(); j++) {
      std::cout << points[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';

  // Create a matrix in a different way?
  std::vector<std::vector<double>> A(5, std::vector<double>(2, 0));
  A[0] = std::vector<double>{4.0, 5.0};

  std::cout << "Verify the size of the matrix points :";
  for (std::size_t i = 0; i < A.size(); i++) {
    std::cout << "the size of the row: " << i << " is " << A[i].size() << '\n';
    for (std::size_t j = 0; j < A[i].size(); j++) {
      std::cout << A[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';

  std::cout << "Verify the size of the matrix points :";
  std::cout << A[0].size() << ' ';
  std::cout << '\n';

  // section to study the reference
  std::vector<double> vector_a{1.0, 4.0, 5.1};
  std::vector<double> &vector_reference = vector_a;
  const std::vector<double> vector_copy = vector_a;

  print(vector_a);
  print(vector_reference);
  print(vector_copy);

  vector_a = std::vector<double>{100, 100, 200};
  print(vector_a);
  print(vector_reference);
  print(vector_copy);

  vector_reference[0] = 2.0;
  print(vector_a);
  print(vector_reference);
  print(vector_copy);

  return 0;
}
