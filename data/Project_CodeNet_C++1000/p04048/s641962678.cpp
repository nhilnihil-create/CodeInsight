#include <iostream>
#include <algorithm>
using namespace std;
using int64 = long long;
#define int int64

int solve(int p, int q) {
  int mx = max(p,q);
  int mn = min(p,q);
  if (mx%mn != 0) {
    return solve(mn, mx%mn) + (mx/mn)*2*mn; 
  } else {
    return (mx/mn)*2*mn - mn;
  }
}

signed main(){
  int n,x;cin>>n>>x;
  int ans = x + n-x + solve(x, n-x);
  cout<<ans<<endl;
}