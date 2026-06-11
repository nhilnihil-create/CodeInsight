#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
//#define mod 10E9+7

int main(void) {
  int mod = 1e9+7;
  int n;
  cin >> n;
  vector<int> a(n); rep(i,n)cin>>a[i];
  sort(a.begin(),a.end());

  //あるか判定
  bool key = true;
  vector<int> b(n); rep(i,n) b[i] = abs(n+1-2*(i+1));
  sort(b.begin(),b.end());
  rep(i,n) {
    if(a[i] != b[i]) {key = false; break; }
  }
  if(key) {
    int r = n/2; long ans=1;
    rep(i,r) {
      ans *= 2;
      ans %= mod;
    }
    cout << ans << endl;
  }else {
    cout << 0 << endl;
  }
}