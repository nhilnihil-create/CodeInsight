#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  for (int i = A; i < 100000; i += A) {
    if (i % B == C) return cout << "YES" << "\n", 0;
  }
  cout << "NO" << "\n";
}