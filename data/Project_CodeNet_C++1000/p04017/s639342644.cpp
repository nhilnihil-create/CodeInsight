#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n, len;
  cin >> n;
  int x[n];
  rep(i,n) cin >> x[i];
  cin >> len;
  int p = 1;
  int s = 0;
  while(p <= n) {
    p *= 2;
    s++;
  }
  vector<vector<int>> dp(n+1,vector<int>(s));
  rep(i,n) {
    int c = upper_bound(x,x+n,x[i]+len) - x;
    dp[i][0] = c-1;
  }
  rep(i,s) dp[n][i] = n;
  for(int i = 1; i < s; i++) {
    rep(j,n) {
      dp[j][i] = dp[dp[j][i-1]][i-1];
    } 
  }
  int q;
  cin >> q;
  int ans[q];
  rep(i,q) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    if(a > b) swap(a,b);
    int l = 0, r = n;
    while(r - l > 1) {
      int m = (l + r) / 2;
      int p = a;
      rep(k,s) {
        if(m & (1<<k)) {
          p = dp[p][k];
        }
      }
      if(p >= b) r = m;
      else l = m;
    }
    ans[i] = r;
  }
  for(auto x : ans) cout << x << endl;
  return 0;
}