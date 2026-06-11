// by newbiechd
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl

const int N_MAX = 200003;
int K, fa[N_MAX], ans;
vector<int> g[N_MAX];
int dfs(int x) {
  int lim = K - (x != 1), ret = 0;
  for (int y : g[x]) {
    int temp = dfs(y);
    if (temp >= lim)
      ++ans;
    else
      ret = std::max(temp + 1, ret);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n >> K;
  for (int i = 1; i <= n; ++i)
    cin >> fa[i];
  for (int i = 2; i <= n; ++i)
    g[fa[i]].push_back(i);
  if (fa[1] != 1)
    ++ans;
  dfs(1);
  cout << ans << endl;
  return 0;
}
