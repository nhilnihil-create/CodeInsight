#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int max_a = 0, max_a_b = n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a > max_a) {
      max_a = a;
      max_a_b = b;
    }
  }
  cout << max_a + max_a_b << endl;
  return 0;
}