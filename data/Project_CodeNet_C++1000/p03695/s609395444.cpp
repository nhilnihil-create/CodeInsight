#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<bool> color(8, false);
  int free = 0;
  rep(i,n) {
    int a;
    cin >> a;
    if (a >= 3200) free++;
    else color[a/400] = true;
  }
  int nofree = 0;
  for (bool b : color) nofree += b;
  printf("%d %d\n", max(1, nofree), max(1, nofree+free));
  return 0;
}