#include <bits/stdc++.h>

using namespace std;

template<class T> inline T sqr(const T& a) {
  return a * a;
}

template<class T> inline int len(const T &c) {
  return static_cast<int>(c.size());
}

typedef long long li;
const int N = 100100;

vector<int> g[N];
bool used[N];
int od[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  li single = 0;
  vector<li> o, e;
  for (int i = 0; i < n; ++i) {
    if (used[i]) {
      continue;
    }
    if (g[i].empty()) {
      ++single;
      used[i] = true;
      continue;
    }
    int card = 1;
    bool odd = false;
    queue<int> q;
    q.push(i);
    od[i] = 0;
    used[i] = true;
    while (!q.empty()) {
      int fm = q.front();
      q.pop();
      int nod = 1 - od[fm];
      for (int to : g[fm]) {
        if (used[to]) {
          if (nod != od[to]) {
            odd = true;
          }
        } else {
          ++card;
          q.push(to);
          od[to] = nod;
          used[to] = true;
        }
      }
    }
    if (odd) {
      o.push_back(card);
    } else {
      e.push_back(card);
    }
  }

  printf("%lld\n", sqr(single) + single * (n - single) * 2 + sqr<li>(len(o)) + sqr<li>(len(e)) * 2 + li(len(o)) * li(len(e)) * 2);
  return 0;
}
