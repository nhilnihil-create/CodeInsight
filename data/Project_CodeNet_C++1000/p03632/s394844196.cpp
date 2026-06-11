#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main() {
  int A=0, B=0, C=0, D=0;
  cin >> A >> B >> C >> D;
  int lower, upper = 0;
  lower = max(A, C);
  upper = min(B, D);
  cout << max(upper - lower, 0) << endl;
}