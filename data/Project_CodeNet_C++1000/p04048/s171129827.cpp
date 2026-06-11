#include <iostream>


long long rec(long long a, long long b) {
  if(b == 0)
    return -a;

  return (a/b)*2*b + rec(b, a%b);
}

int main() {
  long long n, x;
  std::cin >> n >> x;

  std::cout << n + rec(std::min(n-x, x), std::max(n-x, x)) << std::endl;
  
  return 0;
}
