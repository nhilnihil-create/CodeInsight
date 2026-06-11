#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;



int main(){
  int n, m;
  cin >> n >> m;
  --n;

  vector<int> ship(n+1);
  REP(i,n+1) ship[i] = 0;
  REP(i,m){
    int a, b;
    cin >> a >> b;
    --a, --b;
    if(a == 0) ship[b]++;
    if(b == n) ship[a]++;
  }

  bool ok = false;

  REP(i,n+1){
    if(ship[i] >= 2) {
      ok = true;
      break;
    }
  }

  if(ok) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
  return 0;
}
