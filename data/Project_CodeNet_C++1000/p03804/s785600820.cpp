#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,m; cin >> n >> m;
  vector<string> a(n); rep(i,n) cin >> a[i];
  vector<string> b(m); rep(i,m) cin >> b[i];

  bool exist = false;
  rep(ay,n){
    rep(ax,n){
      if(ax+m-1>=n || ay+m-1>=n) continue;

      bool match = true;
      rep(y,m){
	rep(x,m){
	  if(a[ay+y][ax+x] != b[y][x]) match = false;
	}
      }
      if(match) exist = true;
    }
  }

  if(exist) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
