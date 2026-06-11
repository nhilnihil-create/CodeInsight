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
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define INF (1LL<<30)
#define LLINF (1LL<<60)
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll

signed main(void)
{
  int n, sum = 0, idx;
  cin >> n;
  FOR(i, 1, n+1) {
    sum += i;
    if(sum >= n) {
      idx = i;
      break;
    }
  }
  VI ans;
  while(n) {
    if(n >= idx) {
      n -= idx;
      ans.push_back(idx);
    }
    idx--;
  }
  for(int i: ans) cout << i << endl;
  return 0;
}
