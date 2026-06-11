#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c; cin >> a >> b >> c;
  bool exist = false;
  for (int i = 0; i < b; i++) {
    if (a * i % b == c) exist = true;
  }
  if (exist) cout << "YES" << endl;
  else cout << "NO" << endl;
}