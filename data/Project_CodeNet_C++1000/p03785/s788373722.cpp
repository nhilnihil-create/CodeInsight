#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() { 
  int N;
  ll C, K;
  cin >> N >> C >> K;
  vector<ll> T(N);
  rep(i, N) cin >> T[i];
  sort(T.begin(), T.end());
  int ans = 0;
  rep(i, N) {
    int index = upper_bound(T.begin(), T.end(), T[i]+K) - T.begin();
    ans++;
    if (index - i <= C) {
      i = index - 1;
    } else {
      i += (C - 1);
    }
  }
  cout << ans << endl;
  return 0;
}