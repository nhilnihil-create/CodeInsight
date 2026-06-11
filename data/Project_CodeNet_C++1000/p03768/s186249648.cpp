#include <cmath>
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>>g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector <tuple <int, int, int> > e;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int v, d, c;
    cin >> v >> d >> c;
    v--;
    e.push_back(tuple<int, int, int>{v, d, c});
  }
  reverse(e.begin(), e.end());
  vector <vector <bool> > u(n, vector <bool> (11));
  vector <int> ans(n);
  function<void(int,int,int)>dfs=[&](int v, int d,int col) {
    if (u[v][d]) return;
    u[v][d] = true;
    if (d == 0) {
      ans[v]=col;
    }else{
      dfs(v,d-1,col);
      for(int j:g[v]){
        dfs(j,d-1,col);
      }
    }
  };
  for (auto c : e) {
    dfs(get<0>(c),get<1>(c),get<2>(c));
  }
  for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}
