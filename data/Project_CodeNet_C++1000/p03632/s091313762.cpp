#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int N = min(B, D) - max(A, C);
  if(N < 0) {
    N = 0;
  }
  cout << N << endl;
}
