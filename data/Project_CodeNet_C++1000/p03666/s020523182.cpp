#include <iostream>

int main() {
  long long n, a, b, c, d;
  std::cin >> n >> a >> b >> c >> d;

  for (long long m=0; m<n; m++) {
    if ( ( (n-1-m) * c + m * -d ) <= (b - a) &&
         (b - a) <= ( m * -c + (n-1-m) * d ) ) {
      std::cout << "YES" << std::endl;
      return 0;
    }
  }

  std::cout << "NO" << std::endl;

  return 0;
}
