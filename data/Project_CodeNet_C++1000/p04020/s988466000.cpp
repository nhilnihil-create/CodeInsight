#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const ll INF = 1LL<<60;

int main()
{
  int n; cin>>n;
  vector<ll> a(n);
  rep(i, n) cin>>a[i];
  ll ans = 0;
  rep(i, n) {
    if (i > 0) {
      if (a[i-1] > 0 && a[i] > 0) {
        ans++;
        a[i-1]--;
        a[i]--;
      }
    }
    ans += a[i]/2;
    a[i] = a[i]%2;
  }
  cout << ans << endl;

  return 0;
}
