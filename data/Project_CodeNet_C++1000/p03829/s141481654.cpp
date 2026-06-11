#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define MOD 1000000007

int main(void) {
  ll n, a, b;
  cin >> n >> a >> b;
  ll x[n];
  rep(i,n) cin >> x[i];
  ll ans=0;
  rep(i,n-1) { //now..x[i],next..x[i+1]
    ll diff=abs(x[i]-x[i+1]);
    ans += min(diff*a,b);
  }
  cout << ans << endl;
}