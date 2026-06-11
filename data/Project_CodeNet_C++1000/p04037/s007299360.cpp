#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n+10);
  for ( int i = 0; i < n; ++ i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  for ( int i = 0; i < n; ++ i) {
    if( i+2 > a[i+1]) {
      int ret = 0;
      for ( int k = i+1; a[k] == i+1; ++ k) {
        ret ^= 1;
      }
      ret |= (a[i]-i+1)&1;
      cout << (ret ? "First\n" : "Second\n");
      return 0;
    }
  }
  return 0;
}