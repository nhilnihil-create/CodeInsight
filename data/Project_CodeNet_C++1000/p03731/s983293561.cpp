#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  ll T; cin >> T;
  vector<ll> t(n); rep(i,n) cin >> t[i];

  ll ans = 0;
  for(int i = 1;i<n;i++) ans += min(t[i]-t[i-1],T);

  ans += T;
  cout << ans << endl;
  
  return 0;
}
