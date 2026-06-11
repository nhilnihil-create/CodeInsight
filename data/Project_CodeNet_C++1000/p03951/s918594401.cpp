
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
  cin >> n;
  string s, t;
  cin >> s >> t;
  REP(i, n) {
    bool ok = true;
    REP(j, n - i) {
      if(s[i + j] != t[j]) ok = false;
    }
    if(ok) {
      cout << n + i << endl;
      return 0;
    }
  }
  cout << n * 2 << endl;
      

}
