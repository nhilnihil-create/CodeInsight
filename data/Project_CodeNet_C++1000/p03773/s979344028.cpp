#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int c = a + b;
  if (c < 24) cout << c << endl;
  else cout << c - 24 << endl;
}