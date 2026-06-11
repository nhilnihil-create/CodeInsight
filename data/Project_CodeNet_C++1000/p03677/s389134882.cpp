#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const ll INF = 1e17;

int main(){
  ll n, m;
  cin >> n >> m;
  ll a[n];
  rep(i,n) cin >> a[i];
  vector<ll> mx(m+2,0);
  vector<ll> s(m+2,0);
  rep(i,n-1) {
    s[1] += a[i+1]; 
    if(a[i] > a[i+1]) {
      s[a[i+1]] += m - a[i];
      s[a[i]] -= m - a[i];
      mx[1] += 1;
      mx[a[i+1]] -= 1;
      s[a[i]] += m;
      mx[a[i]] += 1; 
    } else {
      mx[a[i]] += 1;
      mx[a[i+1]] -= 1;
      s[a[i+1]] -= a[i];
      s[1] -= a[i];
      s[a[i]] += a[i];
    }
  }
  ll ans = INF;
  for(int i = 1; i <= m; i++) {
    s[i] += s[i-1];
    mx[i] += mx[i-1];
    ans = min(ans,s[i]-mx[i]*i);
  }
  cout << ans << endl;
  return 0;
}