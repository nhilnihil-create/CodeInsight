#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}

string cf = "CODEFESTIVAL2016";

int main(void)
{
  string s; cin >> s;
  ll c = 0;
  REP(i, cf.size()) {
    if(cf[i] != s[i]) c++;
  }
  cout << c << endl;
}
