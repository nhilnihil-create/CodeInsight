#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

// vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  return s;
}

map<int, vector<int>> goods;
int values[4][101];
int W;
int w0;

int limit(int w) {
  if (goods.find(w) == goods.end()) return 0;
  else return goods[w].size();
}

int value(int i, int j, int k, int l) {
  int ret = 0;
  ll w = 0;
  w += (ll)i*w0;
  w += (ll)j*(w0+1);
  w += (ll)k*(w0+2);
  w += (ll)l*(w0+3);
  if (w > (ll)W) return 0;
  ret += values[0][i];
  ret += values[1][j];
  ret += values[2][k];
  ret += values[3][l];
  return ret;
}

int main() {
  int n;
  cin >> n >> W;
  for (int i = 0; i < n; ++i) {
    int w, v;
    cin >> w >> v;
    if (i == 0) w0 = w;
    goods[w].push_back(v);
  }
  for (auto it: goods) {
    int w = it.first;
    vector<int> &g = it.second;
    sort(g.begin(), g.end(), greater<int>());
    int v = 0;
    for (int i = 0; i < g.size(); ++i) {
      values[w-w0][i+1] = values[w-w0][i] + g[i];
    }
  }
  int ans = 0;
  for (int i = 0; i <= limit(w0); ++i) {
    for (int j = 0; j <= limit(w0+1); ++j) {
      for (int k = 0; k <= limit(w0+2); ++k) {
        for (int l = 0; l <= limit(w0+3); ++l) {
          int v = value(i, j, k, l);
          ans = max(ans, v);
        }
      }
    }
  }
  cout << ans << endl;
}

