#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  
  ll ans = 1;
  for(int i=0; i<n; i++) {
    if(i==0) ans *= m;
    else ans *= m-1;
  }
  cout << ans << endl;
  return 0;
}