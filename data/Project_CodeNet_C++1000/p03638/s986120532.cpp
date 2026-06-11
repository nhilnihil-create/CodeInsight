#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

/*{
  }*/

using vi = vector<int>;
using vvi = vector<vi>;
using P = pair<int,int>;

signed main() {
  int h, w, n;
  cin >> h >> w >> n;

  vi a(n);
  rep(i, 0, n) cin >> a[i];

  vvi ans(h, vi(w));
  int col = 1;
  int i = 0, j = 0;
  rep(y, 0, h){
    rep(x, 0, w){
      if(y%2) ans[y][x] = col;
      else ans[y][w-1-x] = col;

      j++;
      if(j == a[i]) { i++; j = 0; col++; }
    }
  }

  rep(i, 0, h) rep(j, 0, w) cout << ans[i][j] << " \n"[j==w-1];

  return 0;
}

