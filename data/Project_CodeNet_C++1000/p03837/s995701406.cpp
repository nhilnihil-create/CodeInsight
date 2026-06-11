#include "bits/stdc++.h"
using namespace std;

// Inserted snippets: io, root
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }
// End snippets

int dist[105][105];
int a[1005], b[1005], c[1005];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  int n, m; read(n, m);

  rep(i, 0, n) rep(j, 0, n)
    dist[i][j] = i == j ? 0 : 0x3f3f3f3f;
  rep(i, 0, m) {
    read(a[i], b[i], c[i]);
    --a[i], --b[i];
    chmin(dist[a[i]][b[i]], c[i]);
    chmin(dist[b[i]][a[i]], c[i]);
  }
  rep(k, 0, n) rep(i, 0, n) rep(j, 0, n)
    chmin(dist[i][j], dist[i][k] + dist[k][j]);
  int g = 0;
  rep(i, 0, m)
    if (c[i] > dist[a[i]][b[i]])
      g++;
  write(g);
}
