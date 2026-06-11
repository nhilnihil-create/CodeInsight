#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  ll n;
  cin >> n;
  vll a(n);
  rep(i,n) cin >> a.at(i);
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  ll ans = 1;
  int cnt = 0;
  rep(i,n-1) {
    if(a[i]==a[i+1]) {
      ans *= a[i];
      cnt++;
      i++;
      if(cnt==2) {
        cout << ans << endl;
        return 0;
      }
    }
  }
  cout << 0 << endl;
  return 0;
}