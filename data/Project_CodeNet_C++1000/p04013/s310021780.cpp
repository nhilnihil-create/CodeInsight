#ifndef _TEMPLATE_ROOT
#define _TEMPLATE_ROOT
#include "bits/stdc++.h"
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repl(i, a, b) for(ll i = a; i < (b); ++i)
#define repd(i, a, b) for(int i = b; i >= (a); --i)
#define repdl(i, a, b) for(ll i = b; i >= (a); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
#endif
#ifndef _TEMPLATE_IO
#define _TEMPLATE_IO

template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }
#endif
using namespace std;

ll dp[55][2505];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  dp[0][0] = 1;
  int n, a; read(n, a);

  rep(i, 0, n) {
    int t; read(t);
    for (int i = 50; i >= 0; i--) for (int j = 2501; j >= 0; j--) if (dp[i][j])
      dp[i + 1][j + t] += dp[i][j];
  }

  ll ans = 0;
  rep(i, 1, n + 1) {
    ans += dp[i][a * i];
  }
  write(ans);
}

