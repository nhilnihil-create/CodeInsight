#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
  string s;
  cin >> s;
  ll n = s.size();
  map<char, ll> mp;
  REP(i,n) mp[s[i]]++;
  
  ll ans = n*(n-1)/2;
  for(auto p: mp) ans -= p.second*(p.second-1)/2;
  cout << ans+1 << '\n';
  return 0;
}
