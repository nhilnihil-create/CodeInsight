#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define RFOR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define LL long long
#define INF INT_MAX

const double EPS = 1e-14;
const double PI  = acos(-1.0);


LL mod = 1000000007;

int main(){
  int n;
  cin >> n;

  vector<int> a(n);
  REP (i, n) {
    cin >> a[i];
  }

  vector<int> b(n);
  REP (i, n) {
    cin >> b[i];
  }

  int x = 0;
  FOR (i, 1, n) {
    if (a[i] != a[i - 1]) x = i;
  }

  int y = n - 1;
  RFOR (i, 1, n) {
    if (b[i] != b[i - 1]) y = i - 1;
  }

  if (x > y || (x == 0 && y == n - 1 && a[0] != b[0])) {
    cout << 0 << endl;
    exit(0);
  }

  LL ans = 1;
  FOR (i, 1, n - 1) {
    if (a[i] == a[i - 1] && b[i + 1] == b[i]) {
      ans = ans * min(a[i], b[i]) % mod;
    }
  }

  cout << ans << endl;
}
