#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;

int main()
{
  int n, k; cin>>n>>k;
  vector<ll> a(n, 0);
  rep(i, n) cin>>a[i];
  ll nin = 1LL<<60;
  rep(bits, 1<<(n-1)) {
    ll bef = a[0];
    ll cost = 0;
    int nk = 1;
    for (int i=1; i<n; i++) {
      if (bits>>(i-1)&1) {
        cost += max(0LL, bef+1-a[i]);
        bef = max(bef+1, a[i]);
        nk++;
      } else {
        if (bef < a[i]) {
          bef = a[i];
          nk++;
        }
      }
    }
    if (k <= nk) nin = min(nin, cost);
  }
  cout << nin << endl;

  return 0;
}
