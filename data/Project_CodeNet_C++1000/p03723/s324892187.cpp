#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define MOD 1000000007
#define INF 1000000000
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(a) (a).begin(), (a).end()
#define __DEBUG__
#ifdef __DEBUG__
#define CH_P(a) cout <<"check_point("<<#a<<")" << "\n";
#define DEBUG(x) cout<<#x<<":"<<x<<"\n"
#define DEBUGS(v) cout << #v << ":";for(auto x:v){cout<<x<<" ";}cout<<"\n"
#endif
#ifndef __DEBUG__
#define CH_P(a) 
#define DEBUG(x) 
#define DEBUGS(v) 
#endif
/* clang-format on */

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (a == b && b == c) {
    cout << -1 << endl;
    return 0;
  }
  ll cnt = 0;
  while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
    cnt++;
    ll t1, t2, t3;
    t1 = a / 2;
    t2 = b / 2;
    t3 = c / 2;
    a = t2 + t3;
    b = t1 + t3;
    c = t1 + t2;
  }
  cout << cnt << endl;
  return 0;
}
