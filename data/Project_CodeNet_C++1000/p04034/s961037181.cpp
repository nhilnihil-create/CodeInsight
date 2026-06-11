#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

int cnt [MAX_N];
int red [MAX_N];

void put (int from, int to) {
  cnt[from]--;
  cnt[to]++;
  red[to] |= red[from];
  if (cnt[from] == 0) red[from] = 0;
}

int main () {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cnt[i] = 1;
  }
  red[1] = 1;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    put(u, v);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += red[i];
  }
  cout << ans << endl;
}
