#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}



int main(void)
{
  ll n;
  vector<ll> a;
  cin >> n;
  REP(i, n) {
    ll a1;
    cin >> a1;
    a.push_back(a1 - 1);
  }

  ll cnt = 0;
  REP(i, n) {
    if(i == a[a[i]]) cnt ++;
  }
  cout << (cnt / 2) << endl;
    
}
