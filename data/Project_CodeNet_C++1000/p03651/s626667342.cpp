#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

set<ll> a;

ll gcd(ll a, ll b)
{
  if(a < b) {
    ll c = a;
    a = b;
    b = c;
  }
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(void)
{
  ll n, k, a1;
  cin >> n >> k;
  ll agcd, amax = 0;
  REP(i, n) {
    cin >> a1;
    if(i > 0) {
      agcd = gcd(agcd, a1);
    } else {
      agcd = a1;
    }
    if(a1 > amax) amax = a1;
    a.insert(a1);
  }
  if(k % agcd == 0 && k <= amax) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}
