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
  ll n, m = 0, M = 0;
  cin >> n;
  vector<ll> a(n);
  REP(i, n) { cin >> a[i]; }
  ll r = 0;
  set<ll> c;
  REP(i, n) {
    if (a[i] < 3200)
      c.insert((ll)floor((double)a[i] / 400));
    else
      r++;
  }
  REP(i, 8) {
    if (c.count(i)) {
      m++;
      M++;
    }
  }
  if (r ==n) m++;
  M += r;
  cout << m << " " << M << endl;
  return 0;
}
