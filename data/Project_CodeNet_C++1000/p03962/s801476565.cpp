#include<iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << ((a == b && b == c)?1:((a == b || b == c || c == a)?2:3)) << std::endl;
}