#include <bits/stdc++.h>
using namespace std;
int main() {
  bool b = false;
  int A, B, C;
  cin >> A >> B >> C;
  for (int i = 1; i <= B; i++) {
    if (A * i % B == C) {
      b = true;
      break;
    }
  }
  if (b) {cout << "YES" << endl;}
  else {cout << "NO" << endl;}
}