#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using Pi = pair<int, int>;
using Tapris = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int n, m;
  cin >> n >> m;
  vint x(n);
  vint cnt(m);
  map<int, int> mp;
  vector<vint> g(m);
  rep(i, n) {
    cin >> x[i];
    ++cnt[x[i]%m];
    ++mp[x[i]];
    g[x[i]%m].push_back(x[i]);
  }
  rep(i, m) {
    sort(all(g[i]));
    g[i].erase(unique(all(g[i])), g[i].end());
  }
  int ans = 0;
  ans += cnt[0]/2;
  if(m%2 == 0) ans += cnt[m/2]/2;
  reps(i, 1, (m+1)/2) {
    int a = i, b = m-i;
    if(cnt[a] < cnt[b]) swap(a, b);
    //cout<<a<<" "<<b<<" "<<cnt[a]<<" "<<cnt[b]<<endl;
    rep(j, g[a].size()) {
      if(cnt[a] == cnt[b]) break;
      int x = min(mp[g[a][j]]/2, (cnt[a]-cnt[b])/2);
      ans += x;
      cnt[a] -= x*2;
    }
    ans += cnt[b];
  }
  cout << ans << endl;

  return 0;
}
