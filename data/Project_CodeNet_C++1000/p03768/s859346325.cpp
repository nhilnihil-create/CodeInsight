#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;

void Process(int n, vector<vi>& g, vi& color, vi& pot, int v, int d, int c) {
  vector<ii> q = {make_pair(v, d)};
  for (int i = 0; i < q.size(); ++i) {
    int at = q[i].first;
    int curPot = q[i].second;
    if (curPot <= pot[at]) continue;
    if (color[at] == 0) color[at] = c;
    pot[at] = curPot;
    if (curPot == 0) continue;
    for (int to : g[at]) q.push_back(make_pair(to, curPot - 1));
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vi> g(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int q;
  cin >> q;
  vi v(q), d(q), c(q);
  for (int i = 0; i < q; ++i) {
    cin >> v[i] >> d[i] >> c[i];
    v[i]--;
  }
  vi color(n), dist(n, -1);
  for (int i = q - 1; i >= 0; i--) Process(n, g, color, dist, v[i], d[i], c[i]);
  for (int i = 0; i < n; ++i) cout << color[i] << endl;
  return 0;
}
