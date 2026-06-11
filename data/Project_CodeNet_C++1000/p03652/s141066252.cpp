#include <iostream>
#include <cstdio>
using namespace std;

int n, m, mx, midx;
int a[333][333], idx[333], cnt[333], used[333];

int main() {
  scanf("%d%d", &n, &m);
  for(int i=0; i < n; ++i) for(int j=0; j < m; ++j) scanf("%d", &a[i][j]);

  int ans = 1e9;
  while(true) {
    bool update = false;
    mx = 0, midx = 0;
    for(int i = 1; i <= m; ++i) cnt[i] = 0;
    for(int i = 0; i < n; ++i) {
      if(idx[i] == m) continue;
      else {
        ++cnt[a[i][idx[i]]];
        update = true;
      }
    }
    if(!update) break;

    for(int i = 1; i <= m; ++i) {
      if(mx < cnt[i]) {
        mx = cnt[i];
        midx = i;
      }
    }
    used[midx] = 1;
    for(int i = 0; i < n; ++i) while(used[a[i][idx[i]]]) ++idx[i];
    ans = min(ans, mx);
  }
  printf("%d", ans);
  return 0;
}