#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

int main(void) {
  ll N;
  cin >> N;
  vector<ll> A(N);
  REP(i, 0, N) cin >> A[i];
  vector< vector<ll> > E(N);
  REP(i, 0, N - 1) {
    ll A, B;
    cin >> A >> B; A--; B--;
    E[A].push_back(B);
    E[B].push_back(A);
  }

  ll root = 0;
  REP(i, 0, N) if(E[i].size() == 1) root = i;

  function<ll (ll, ll, bool&)> dfs = [&](ll v, ll p, bool &ok) {
    if(v != root && E[v].size() == 1) return A[v];
    vector<ll> c;
    for(ll u : E[v]) if(u != p) c.push_back(dfs(u, v, ok));
    ll sum = accumulate(c.begin(), c.end(), 0LL);
    ll t = A[v] * 2 - sum;
    ok = ok && 0 <= t && t <= A[v];
    REP(i, 0, c.size()) ok = ok && 0 <= c[i] && c[i] <= A[v];
    return t;
  };

  bool ok = true;
  cout << (dfs(root, -1, ok) == A[root] && ok ? "YES" : "NO") << endl;
}
