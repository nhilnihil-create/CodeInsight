#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};
int sy,sx,gy,gx;

int main(){
  int n,k; cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  ll ans = 1LL<<59;
  for(int bit = 0; bit < (1<<n); bit++){
    ll now = a[0], money = 0;
    int cnt = 1;
    for(int i = 1; i < n; i++){
      if((bit>>i)&1){
        cnt++;
        if(now < a[i]){
          now = a[i];
        }else{
          money += now - a[i] + 1;
          now++;
        }
      }else{
        if(now < a[i]){
          now = a[i];
        }
      }
    }
    if(cnt == k) ans = min(ans, money);
  }
  cout << ans << endl;
  return 0;
}
