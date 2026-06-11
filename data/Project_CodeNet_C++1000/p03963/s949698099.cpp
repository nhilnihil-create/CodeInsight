#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;

void solve(int N, int K) {
  ll ans = K;
  rep(i, N - 1)
    ans *= K - 1;
  cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;

  solve(N, K);

  return 0;
}
