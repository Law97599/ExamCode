#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  if (b < 10) {
    std::cout << (11 - a) << std::endl;
  } else {
    std::cout << (b + 2 - a) << std::endl;
  }
  return 0;
}