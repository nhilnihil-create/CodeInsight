#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  for (int i = 0; i < b; i++) {
    int amari = a * i % b;
    if (amari == c) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
