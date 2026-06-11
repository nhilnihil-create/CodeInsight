#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  long long aa = a[0], bb = b[0];
  for (int i = 0; i < n; i++) {
    long long t = max((aa + a[i] - 1) / a[i], (bb + b[i] - 1) / b[i]);
    aa = a[i] * t;
    bb = b[i] * t;
  }
  cout << aa + bb << endl;

  return 0;
}
