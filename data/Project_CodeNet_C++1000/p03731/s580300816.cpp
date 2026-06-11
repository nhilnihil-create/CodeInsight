#include <bits/stdc++.h>
#define rep(i,a,n) for(int i =a; i<n; i++)
#define ll long long
using namespace std;

int main() {
  int N,T; cin >> N >> T;
  ll t[N]; rep(i,0,N) cin >> t[i];
  
  ll ans = T;
  rep(i,1,N) {
    if (t[i-1] + T > t[i]) ans -= T + t[i-1] - t[i];
    ans += T;
  }

  cout << ans << endl;
}  