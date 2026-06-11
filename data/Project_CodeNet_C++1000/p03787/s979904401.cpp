#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N, M, U, V;
vector<ll> E[100000];
bool used1[200000], used2[200000];

ll dfs1(ll v) {
  if(used1[v]) return 0;
  used1[v] = true;

  ll ret = 1;
  for(ll u : E[v]) ret += dfs1(u);
  return ret;
}

ll dfs2(ll v, ll s) {
  if(used2[v + N * s]) return 0;
  used2[v + N * s] = true;

  ll ret = 1;
  for(ll u : E[v]) ret += dfs2(u, 1 - s);
  return ret;
}

int main(void) {
  cin >> N >> M;
  REP(i, 0, M) {
    cin >> U >> V; U--; V--;
    E[U].push_back(V);
    E[V].push_back(U);
  }

  ll iso = 0, even = 0, odd = 0;
  REP(i, 0, N) used1[i] = false;
  REP(i, 0, N * 2) used2[i] = false;
  REP(i, 0, N) if(!used1[i]) {
    ll z = dfs1(i), w = dfs2(i, 0);
    if(z == 1) iso++;
    else if(w == z) even++;
    else if(w == z * 2) odd++;
  }

  cout << odd * odd + (even * odd * 2) + even * even * 2 + (iso * (N - iso) * 2 + iso * iso) << endl;
}
