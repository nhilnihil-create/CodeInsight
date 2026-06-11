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
  int n;
  cin >> n;
  vector<int> a(n+1);
  REP2(i,1,n+1) cin >> a[i];

  int cnt = 0;
  int now = 1;
  bool ok = false;
  REP(i,n){
    if(now == 2){
      ok = true;
      break;
    }
    now = a[now];
    cnt++;
  }

  if(now == 2) {
    ok = true;
  }

  if(ok) cout << cnt << endl;
  else cout << -1 << endl;
  return 0;
}
