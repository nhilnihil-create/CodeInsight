#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const ll mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vi cnt(n,0);
  vi a(n);
  rep(i,n) {
    cin >> a.at(i);
    cnt[a[i]]++;
  }
  if(n%2==0) {
    bool ok = true;
    for(int i = 1; i <= n-1; i+=2) {
      if(cnt[i]!=2) ok = false;
    }
    if(!ok) cout << 0 << endl;
    else {
      int m = n/2;
      ll ans = 1;
      rep(i,m) {
        ans *= 2;
        ans %= mod;
      }
      cout << ans << endl;
    }
  }
  else {
    bool ok = true;
    for(int i = 0; i <= n-1; i+=2) {
      if(i==0) {
        if(cnt[i]!=1) ok = false;
      }
      else {
        if(cnt[i]!=2) ok = false;
      }
    }
    if(!ok) cout << 0 << endl;
    else {
      int m = (n-1)/2;
      ll ans = 1;
      rep(i,m) {
        ans *= 2;
        ans %= mod;
      }
      cout << ans << endl;
    }
  }
  return 0;
}