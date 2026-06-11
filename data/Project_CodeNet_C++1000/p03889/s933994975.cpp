#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define MOD 1000000007
#define INF (1LL<<25)     //33554432
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll

signed main(void)
{
  string s;
  cin >> s;
  string t = s;

  REP(i, s.size()/2) swap(s[i], s[s.size()-i-1]);
  REP(i, s.size()) {
    if(s[i] == 'b') s[i] = 'd';
    else if(s[i] == 'd') s[i] = 'b';
    else if(s[i] == 'p') s[i] = 'q';
    else if(s[i] == 'q') s[i] = 'p';
  }
  if(s == t) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
