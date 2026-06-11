#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  sort(v.rbegin(), v.rend());
  
  int ans = 0;
  for(int i=0; i<k; i++) ans += v[i];
  cout << ans << endl;
  return 0;
}