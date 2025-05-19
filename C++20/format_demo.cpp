#include <iostream>
#include <format>
#include <string>

int main() {
  int age = 30;
  std::string name = "Alice";
  double pi = 3.14159;

  std::string message = std::format("Name: {}, Age: {}, Pi: {:.2f}", name, age, pi);
  std::cout << message << std::endl; // Output: Name: Alice, Age: 30, Pi: 3.14

  return 0;
}

