#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

ll lcm(ll l, ll r);
ll gcd(ll l, ll r);

int main() {
  int N;
  cin >> N;

  vector<ll> T(N);
  rep(i,0,N-1) cin >> T[i];

  rep(i,1,N-1) {
    T[i] = lcm(T[i-1], T[i]);
  }

  cout << T[N-1] << endl;
  return 0;
}

ll lcm(ll l, ll r)
{
  ll d = gcd(l, r);
  return l / d * r;
}

ll gcd(ll l, ll r)
{
  ll a = max(l, r);
  ll b = min(l, r);
  ll c = a % b;
  while (c != 0)
  {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}
