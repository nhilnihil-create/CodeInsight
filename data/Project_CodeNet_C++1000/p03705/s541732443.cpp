#include <bits/stdc++.h>
using namespace std;

long long n, a, b;

int main() {
  cin >> n >> a >> b;
  if (a > b)
    cout << 0 << endl;
  else if (n == 1)
    cout << (a == b) << endl;
  else {
    b -= a;
    cout << (n - 2) * b + 1 << endl;
  }
  return 0;
}
