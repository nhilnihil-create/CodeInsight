#include<iostream>
int main () {
  int a, b;
  std::cin >> a >> b;
  int c = (a + b) % 24;
  std::cout << c << std::endl;
}