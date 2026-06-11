#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  ll n;
  cin >> n;
  ll ans = 1;
  rep(i,n){
    ans = (ans * (i+1)) % 1000000007;
  }
  cout << ans << endl;
  return 0;
}