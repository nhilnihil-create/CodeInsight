#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D, S1, S2;
  cin >> A >> B >> C >> D;
  S1 = A * B;
  S2 = C * D;
  if (S1 >= S2) {
    cout << S1;
  } else {
    cout << S2;
  }
}
