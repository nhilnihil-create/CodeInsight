#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  int n,k,x,y;
  cin >> n >> k >> x >> y;
  int ans = 0;
  if(n <= k) ans = x*n;
  else if(k < n) ans = x*k + y * (n-k);
  cout << ans << endl;
}