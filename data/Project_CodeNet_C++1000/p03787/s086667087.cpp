#include <bits/stdc++.h>
using namespace std;

long n, m;
vector<int> G[100000];
int col[100000];

bool isb(int from, int c) {
  if (col[from] != 0) {
    if (col[from] == c) return true;
    return false;
  }
  col[from] = c;
  bool ret = true;
  for (int to : G[from]) {
    if (!isb(to, -c)) {
      ret = false;
    }
  }
  return ret;
}

int sub(int from) {
  return isb(from, 1);
}

int main() {
  cin >> n >> m;
  for (int j = 0; j < m; ++j) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  long cnt[2] = {};
  long iso = 0;
  for (int i = 0; i < n; ++i) {
    if (G[i].empty()) {
      ++iso;
      continue;
    }
    if (col[i] != 0) continue;
    int ret = sub(i);
    ++cnt[ret];
  }
  
  long sum = cnt[0] + cnt[1];
  cout << sum * sum + cnt[1] * cnt[1]
        + n * n - (n - iso) * (n - iso) << endl;
}
