#include <iostream>
#include <vector>
using namespace std;

template <class T> T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
template <class T> T lcm(T a, T b) {
	return a / gcd(a, b) * b;
}

int main(void) {
  int N;
  cin >> N;
  unsigned long long ans = 1;
  for (int i = 0; i < N; i++) {
    unsigned long long T;
    cin >> T;
    ans = lcm(ans, T);
  }
  cout << ans << endl;
  return 0;
}
