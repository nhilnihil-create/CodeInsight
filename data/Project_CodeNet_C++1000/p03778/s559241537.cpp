#include <bits/stdc++.h>
using namespace std;

int main() {
  int W, A, B, C, D;
  cin >> W >> A >> C;
  if (A > C) swap(A, C);
  B = A + W;
  D = C + W;
  if (A <= C && C <= B) return cout << 0 << "\n", 0;
  if (A <= D && D <= B) return cout << 0 << "\n", 0;
  cout << C - B << "\n";
}