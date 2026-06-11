#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C, D; cin >> A >> B >> C >> D;
  int s = min(B, D) - max(A, C);
  cout << (s >= 0 ? s : 0) << endl;
}