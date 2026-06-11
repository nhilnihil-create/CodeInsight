#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  ll n, T;
  cin >> n >> T;
  vll t(n);
  rep(i,n) cin >> t.at(i);
  ll ans = 0;
  rep(i,n-1) {
    ll u = t[i+1] - t[i];
    if(u>T) ans += T;
    else ans += u;
  }
  ans += T;
  cout << ans << endl;
  return 0;
}