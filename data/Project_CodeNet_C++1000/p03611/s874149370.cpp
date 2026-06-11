#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int N;
  cin >> N;
  int a[110000];
  FOR(i,0,N) cin >> a[i];
  int d[110000];
  FOR(i,0,N) {
    d[a[i]]++;
  }
  int ans = 0;
  int nearnum;
  FOR(i,0,100000) {
    nearnum = d[i] + d[i+1] + d[i+2];
    ans = max(ans, nearnum);
  }
  cout << ans << endl;
  return 0;
}


