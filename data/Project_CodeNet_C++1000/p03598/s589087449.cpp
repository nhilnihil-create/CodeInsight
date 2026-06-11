#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  
  int x;
  int ans = 0;
  for(int i=0; i<n; i++) {
    cin >> x;
    if(x<=k-x) ans += x*2;
    else ans += (k-x)*2;
  }
  cout << ans << endl;
  return 0;
}