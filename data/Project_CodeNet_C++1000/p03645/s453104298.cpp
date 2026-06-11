#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  map<int, int> mp;
  rep(i,0,M-1) {
    int a, b;
    cin >> a >> b;
    if (a == 1) mp[b]++;
    if (b == N) mp[a]++;
  }

  string ans = "IMPOSSIBLE";
  for (auto p : mp) {
    if (2 <= p.second) ans = "POSSIBLE";
  }

  cout << ans << endl;
  return 0;
}
