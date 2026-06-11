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
  const int CMAX = 9;
  vector<int> color(CMAX);
  REP(i,CMAX) color[i] = 0;
  REP(i,n){
    int a;
    cin >> a;
    REP(i,CMAX-1){
      if(a >= 3200) {
        color[8]++;
        break;
      }
      if(a < (i+1)*400) {
        color[i]++;
        break;
      }
    }
  }

  int cnt = 0;
  REP(i,CMAX-1){
    if(color[i] == 0) continue;
    cnt++;
  }
  // for(auto x: color) cout << x << " ";
  // cout << endl;
  int ansmin = max(1,cnt);
  int ansmax = cnt + color[8];
  cout << ansmin <<" " << ansmax << endl;
  return 0;
}
