#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < ((int)(n)); i++) // 0-indexed昇順

int main()
{
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int S1 = A * B;
  int S2 = C * D;
  if (S1 > S2) {
    cout << S1 << endl;
  } else {
    cout << S2 << endl;
  }
}