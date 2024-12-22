#include <iostream>
#include <ranges>
#include <vector>

int main() {
  std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};

  auto even_numbers = numbers 
    | std::views::filter([](int i) { return i % 2 == 0; })
    | std::views::transform([](int i) { return i * i; });

  for (auto num : even_numbers) {
    std::cout << num << " ";  // Output: 4 16 36 64
  }

  return 0;
}

