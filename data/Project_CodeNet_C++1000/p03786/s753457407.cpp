#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(rng(a));
  ll sum = 0;
  int ans = 0;
  rep(i,n-1) {
    sum += a[i];
    if(sum*2 >= a[i+1]) ans++;
    else ans = 0;
  }
  ans ++;//a[n-1]は確定
  cout << ans << endl;
  return 0;
}