#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n;
  cin >> n;
  map<ll, ll> m;

  for (ll i = 0; i < n; i++)
  {
    ll a;
    cin >> a;
    m[a]++;
  }
  ll cnt = 0;
  for (auto v : m)
  {
    cnt += v.second % 2;
  }
  cout << cnt << endl;
}
