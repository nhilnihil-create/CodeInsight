#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 55);
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<ll> cum(n+1,0), pcum(n+1,0);

  for (int i = 0; i < n; i++) {
    cum[i + 1] = cum[i] + a[i];
    pcum[i + 1] = pcum[i] + max(0, a[i]);
  }

  ll res = -INF;

  for (int i = 0; i + k <= n; i++) {
    int r = i + k;
    ll tmp = max(0LL, cum[r] - cum[i]);
    tmp += pcum[i] + pcum[n] - pcum[r];
    res = max(res, tmp);
  }
  cout << res << endl;
  return 0;
} 