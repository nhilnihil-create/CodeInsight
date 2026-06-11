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
  string s, t;
  cin >> s >> t;
  int tadd = 0;
  bool ok = true;
  REP(i,n){
    REP(j,n - i){
      ok = true;
      if(s[i+j] != t[j]) {
        ok = false;
        break;
      }
    }
    if(ok) {
      tadd = i;
      break;
    }
  }

  int ans = 0;
  if(!ok) ans = 2*n;
  else ans = n + tadd;

  cout << ans << endl;

  return 0;
}
