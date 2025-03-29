#include <iostream>
#include <vector>

constexpr int factorial(int n) {
  if (n <= 1)
    return 1;
  return n * factorial(n - 1);
}

constexpr auto make_vector() {
  std::vector<int> vec = {1, 2, 3};
  vec.push_back(4);
  return vec;
}

int main() {
  constexpr int fact = factorial(5);
  std::cout << "Factorial of 5: " << fact << std::endl;  // Output: 120

  constexpr auto vec = make_vector();
  std::cout << "Vector size: " << vec.size() << std::endl;  // Output: 4
  return 0;
}

