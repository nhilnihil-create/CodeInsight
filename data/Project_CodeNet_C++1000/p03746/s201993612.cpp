#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef vector<vector<ll>> matrix;

int n, m;
vector<int> edges[100005];
bool used[100005];
void solve() {
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  used[1] = true;
  used[edges[1][0]] = true;
  deque<int> ret;
  ret.push_front(1);
  ret.push_back(edges[1][0]);
  while(true) {
    bool upd = false;
    for(int out: edges[ret.front()]) {
      if(!used[out]) {
        ret.push_front(out);
        used[out] = true;
        upd = true;
        break;
      }
    }
    if(upd) continue;
    for(int out: edges[ret.back()]) {
      if(!used[out]) {
        ret.push_back(out);
        used[out] = true;
        upd = true;
        break;
      }
    }
    if(upd) continue;
    break;
  }
  cout << ret.size() << "\n";
  int idx = 0;
  for(int out: ret) {
    cout << out;
    if(++idx == ret.size()) cout << "\n";
    else cout << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
