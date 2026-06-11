#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  for (long long i = floor(sqrt(n)); i >= 1; i--) {
    if (n % i == 0) {
      cout << to_string(n / i).length() << '\n';
      return 0;
    }
  }
  return 0;
}