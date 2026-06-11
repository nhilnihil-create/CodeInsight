#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

ll n, m, s, t;
vector<vector<ll>> to;
deque<ll> ans;
vector<bool> seen;

void dfs(ll cv) {
  FOREACH(nv, to[cv]) {
    if (seen[nv]) continue;
    seen[nv] = true;
    ans.push_back(nv);
    t = nv;
    dfs(nv);
    break;
  }
}

bool isOK(ll cv, bool isLeft) {
  FOREACH(nv, to[cv]) {
    if (seen[nv]) continue;
    if (isLeft) {
      ans.push_front(nv);
      s = nv;
    } else {
      ans.push_back(nv);
      t = nv;
    }
    seen[nv] = true;
    return false;
    break;
  }
  return true;
}
int main() {
  cin >> n >> m;
  to.resize(n);
  seen.resize(n, false);
  REP(i, m) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  s = 0;
  seen[s] = true;
  ans.push_back(s);
  dfs(s);
  // s--tパスができた

  // s,tは条件を満たすか確認
  while (!isOK(s, true))
    ;
  while (!isOK(t, false))
    ;

  ll sz = SZ(ans);
  cout << sz << endl;
  REP(i, sz) { cout << ans[i] + 1 << " \n"[i == sz - 1]; }
}