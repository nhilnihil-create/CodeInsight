#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const ll INF = 1LL<<60;

int main()
{
  ll k, t; cin>>k>>t;
  vector<ll> a(t);
  rep(i, t) cin>>a[i];
  ll x = 0;
  ll sum = 0;
  rep(i, t) {
    x = max(x, a[i]);
    sum += a[i];
  }
  sum -= x;
  cout << max(0LL, x-sum-1) << endl;

  return 0;
}
