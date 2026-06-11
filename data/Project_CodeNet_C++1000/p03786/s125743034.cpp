#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<ll>a(n);
  rep(i,0,n) cin >> a[i];
  sort(a.begin(),a.end());
  vector<ll>sum(n);
  sum[0] = a[0];
  rep(i,1,n) sum[i] = a[i]+sum[i-1];
  reverse(a.begin(),a.end());
  reverse(sum.begin(),sum.end());
  int ans = 1;
  rep(i,1,n){
    if(sum[i]*2 >= a[i-1]) ans++;
    else break;
  }
  cout << ans << endl;
}