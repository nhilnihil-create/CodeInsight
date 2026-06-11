#include <iostream>

using namespace std;

int get_digit(long long x) {
  int cnt = 0;
  while (x > 0) {
    cnt++;
    x /= 10;
  }
  return cnt;
}

long long sqrt_floor(long long x) {
  long long l = 0, r = x + 1, m;
  while (l + 1 < r) {
    m = (l + r) / 2;
    (m <= x / m ? l : r) = m;
  }
  return l;
}

int main() {
  long long N;
  cin >> N;

  long long d = sqrt_floor(N);

  while (d > 0) {
    if (N % d == 0) {
      cout << get_digit(N / d) << endl;
      break;
    }
    --d;
  }
}
