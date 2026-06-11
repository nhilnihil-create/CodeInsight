#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 1e9 + 7;

int main() { 
  int N, M;
  cin >> N >> M;
  if (abs(N-M) > 1) {
    cout << 0 << endl;
    return 0;
  }

  int d = 1, m = 1;
  for (int i = 1; i <= N; i++) d = (ll)d * i % mod;
  for (int j = 1; j <= M; j++) m = (ll)m * j % mod;
  int ans = (ll) d * m % mod;
  if (N == M) ans = (ll) ans * 2 % mod;

  cout << ans << endl;
  return 0;
}