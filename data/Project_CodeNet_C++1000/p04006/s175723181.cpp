#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N; ll x; cin >> N >> x;
  ll a[N]; rep(i,N) cin >> a[i];
  ll mi[N][N];
  rep(i,N) {
    if (i==0) rep(j,N) mi[i][j] = a[j];
    else rep(j,N) mi[i][j] = min(mi[i-1][(j+N-1)%N], mi[i-1][j]);
  }
  ll result = LLINF;
  rep(i,N) {
    ll tmp = 0; rep(j,N) tmp += mi[i][j];
    result = min(result, tmp+x*i);
    // rep(j,N) cout << mi[i][j] << " "; cout << endl;
  }
  cout << result << endl;
  return 0;
}