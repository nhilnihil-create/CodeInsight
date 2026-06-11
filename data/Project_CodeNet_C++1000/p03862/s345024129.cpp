#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int n,x;
  cin >> n >> x;
  ll ans = 0;
  vector<int>a(n+2);
  a[0] = a[n+1] = 0;
  for(int i = 1;i < n+1;i++) cin >> a[i];
  for(int i = 0;i < n+1;i++){
    if(a[i] > x){
      ans += a[i+1];
      a[i+1] == 0;
      ans += a[i]-x;
      a[i] = x;
    }
    else if(a[i]+a[i+1] > x){
      ans += a[i]+a[i+1]-x;
      a[i+1] = x-a[i];
    }
  }
  cout << ans << endl;
}