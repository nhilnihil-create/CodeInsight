#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1LL<<60;
const int mod = 1e9 + 7;
const double eps = 1e-9;

/*{
  }*/

signed main(){
  int n, m;
  cin >> n >> m;

  vvi a(n, vi(m));
  rep(i, 0, n) rep(j, 0, m){
    cin >> a[i][j];
    a[i][j]--;
  }

  set<int> s;
  rep(i, 0, m) s.insert(i);

  vi cur(n);
  int ans = inf;
  rep(i, 0, m){
    vi cnt(m);
    rep(j, 0, n) cnt[a[j][cur[j]]]++; 

    int ma = -1, tmp;
    rep(j, 0, m) if(chmax(ma, cnt[j])) tmp = j;
    chmin(ans, ma);

    s.erase(s.lower_bound(tmp));
    rep(j, 0, n){
      while(*s.lower_bound(a[j][cur[j]]) != a[j][cur[j]]){
        cur[j]++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
