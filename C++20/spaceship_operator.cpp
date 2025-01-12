#include <iostream>
#include <compare>

struct Point {
  int x, y;

  auto operator<=>(const Point&) const = default;
};

int main() {
  Point p1{1, 2}, p2{1, 3};

  if (p1 < p2)
    std::cout << "p1 is less than p2" << std::endl;
  else if (p1 > p2)
    std::cout << "p1 is greater than p2" << std::endl;
  else
    std::cout << "p1 is equal to p2" << std::endl;

  return 0;
}

