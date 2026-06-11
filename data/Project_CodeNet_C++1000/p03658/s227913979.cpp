#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {

  int n,k;
  cin >> n >> k;
  
  vector<int> t(n);
  rep(i,n) cin >> t[i];
  
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());
  
  int ans = 0;
  rep(i,k) ans += t[i];
  
  cout << ans << endl;
  
  
}
