#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, m = 0, c = 0;
  vector<int> vec(101);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> vec.at(i);
  }

  for (int i = 0; i < n; i++) {
    int a = vec.at(i) - 0;
    int b = k - vec.at(i);

    if (a < 0) {
      a *= -1;
    }
    if (b < 0) {
      b *= -1;
    }

    c = min(a, b);
    m += 2 * c;
  }
  cout << m << endl;
}