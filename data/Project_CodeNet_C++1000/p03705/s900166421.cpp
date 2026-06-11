#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  long long A = (n - 1) * a + b;
  long long B = (n - 1) * b + a;
  cout << max((long long) 0, B - A + 1) << '\n';
  return 0;
}