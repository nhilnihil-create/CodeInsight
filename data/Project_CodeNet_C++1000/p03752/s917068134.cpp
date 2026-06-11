#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;
int main(){
  int n,k;cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  ll ans = 1e18;
  rep(bit,1<<n){
    vector<int> temp(n);
    rep(i,n) temp[i] = a[i];

    ll sum = 0;

    if(__builtin_popcount(bit) != k) continue;
    int mx = temp[0]-1;
    //cout << mx << endl;
    rep(i,n){
      if(bit>>i&1){
        //cout << ((bit>>i)&1) << endl;
        //cout << " " << i << endl;
        sum += max(mx+1-temp[i],0);
        temp[i] = max(mx+1,temp[i]);
      }
      if(temp[i]>mx) mx = temp[i];
      //cout << mx << endl;
    }
    //printf("%d %d %d %d %d\n",temp[0],temp[1],temp[2],temp[3],temp[4]);
    ans = min(ans,sum);
  }
  cout << ans << endl;
}