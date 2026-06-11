#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int64_t M, N;
  cin >> M >> N;
  if(M == 1) {
    cout << N;
  }
  else {
    int64_t ans = N;
    rep(i, M - 1) {
      ans *= (N - 1);
    }
    cout << ans;
  }
}