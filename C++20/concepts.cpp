#include <concepts>
#include <iostream>

template<typename T>
concept Number = std::is_arithmetic_v<T>;

template<Number T>
T add(T a, T b) {
  return a + b;
}

int main() {
  std::cout << add(3, 5) << std::endl;       // Valid
  // std::cout << add(3, "hello") << std::endl; // Invalid, doesn't compile
  return 0;
}
