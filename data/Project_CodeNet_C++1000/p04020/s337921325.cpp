#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  ll ans = 0;
  cin >> n;
  vector<int>a(n);
  rep(i,0,n) cin >> a[i];
  rep(i,0,n-1){
    ans += a[i]/2;
    a[i] %= 2;
    if(a[i+1] > 0){
      ans += a[i];
      a[i+1] -= a[i];
    }
  }
  ans += a[n-1]/2;
  cout << ans << endl;
}