#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  if (A % 2 || B % 2 || C % 2) return cout << 0 << "\n", 0;
  if (A == B && B == C) return cout << -1 << "\n", 0;
  int cnt = 0;
  while (true) {
    if (A % 2 || B % 2 || C % 2) break;
    int a = A, b = B, c = C;
    A = b / 2 + c / 2;
    B = a / 2 + c / 2;
    C = a / 2 + b / 2;
    cnt++;
  }
  cout << cnt << "\n";
}