#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N, X, Y;
vector<ll> E[100000];

ll dfs(ll v, ll p) {
  ll g = 0;
  for(ll u : E[v]) if(u != p) g = g ^ (dfs(u, v) + 1);
  return g;
}

int main(void) {
  cin >> N;
  REP(i, 0, N - 1) {
    cin >> X >> Y; X--; Y--;
    E[X].push_back(Y);
    E[Y].push_back(X);
  }

  cout << (dfs(0, -1) != 0 ? "Alice" : "Bob") << endl;
}
