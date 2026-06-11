#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n;
  cin >> n;
  ll a[n];
  rep(i,n) cin >> a[i];
  ll ans = 0;
  ans += a[0]-1;
  int p = 2;
  for(int i = 1; i < n; i++) {
    if(a[i] != p) ans += (a[i]-1)/p;
    else p++;
  }
  cout << ans << endl;
  return 0;
}