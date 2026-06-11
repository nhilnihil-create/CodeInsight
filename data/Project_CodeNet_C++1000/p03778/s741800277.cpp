#include <bits/stdc++.h>
using namespace std;

int main() {
  int W, A, B, C, D;
  cin >> W >> A >> C;
  if (A > C) swap(A, C);
  B = A + W;
  D = C + W;
  cout << ((C - B > 0) ? C - B : 0) << "\n";
}