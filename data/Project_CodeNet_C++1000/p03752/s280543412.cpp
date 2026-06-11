#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const ll INF = 1e14;
const int MOD = 1000000007;

 
int main() {
  int n,k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a.at(i);
  ll ans = INF;
  
  rep(i,pow(2,n)){
    int cnt = 0;
    rep(j,n){
      if(i >> j &1 ) cnt ++;
    }
    if(cnt < k) continue;
    ll now = 0;
    ll mx = 0;
    rep(j,n){
      if(i >> j &1 ){
        if(a.at(j) <= mx ){
          now += mx-a.at(j)+1;
          mx += 1;
        }
      }
      mx = max(a.at(j),mx);
    }
    ans = min(ans,now);
  }
  cout << ans << endl;
        
  return 0;
}


