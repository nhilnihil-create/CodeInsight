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

  int n;
  cin >> n;
  vint x(n);
  rep(i, n) cin >> x[i];

  vint dx(n-1);
  rep(i, n-1) dx[i] = x[i+1]-x[i];

  int m, k;
  cin >> m >> k;
  vint a(m);
  rep(i, m) cin >> a[i], --a[i];

  vint id(n-1);
  iota(all(id), 0);
  rep(i, m) swap(id[a[i]-1], id[a[i]]);

  rep(i, 60) {
    if((k>>i)&1) {
      vint tmp = dx;
      rep(j, n-1) dx[j] = tmp[id[j]];
    }

    vint tmp = id;
    rep(j, n-1) id[j] = tmp[tmp[j]];
  }

  vint ans(n);
  ans[0] = x[0];
  rep(i, n-1) ans[i+1] = ans[i] + dx[i];

  rep(i, n) cout << ans[i] << endl;

  return 0;
}
