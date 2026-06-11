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

void solve()
{
  ll a, b; cin >> a >> b;

  if((a <= 0 && b >= 0) || a == 0 || b == 0) {
    cout << "Zero" << endl;
    return;
  }

  if(a > 0 ) {
    cout << "Positive" << endl;
    return ;
  }
  if((b - a + 1) % 2 == 0) {
    cout << "Positive" << endl;
  } else {
    cout << "Negative" << endl;
  }
  
  //Positive を、負ならば Negative を、0 ならば Zero を出力せよ。
}


int main(void)
{
  // ll t; cin >> t; REP(i, t)
  solve();
}
