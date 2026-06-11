// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  ll n,x,ans=10000000000000;
  cin >> n >> x;
  vector<ll> a(n),ta(n);
  ll best[n][n];
  fill(best[0],best[n],10000000000000);
  for(int i=0;i<n;i++){
    cin >> a[i];
    best[i][0] = a[i];
  }
  for(int i=0;i<n;i++){
    for(int j=1;j<n;j++){
      ll v = (i-j+n)%n;
      best[i][j] = min(best[i][j-1],a[v]);
    }
  }
  for(int i=0;i<n;i++){
    ll tmp = 0;
    for(int j=0;j<n;j++){
      tmp += best[j][i];
    }
    tmp += i*x;
    ans = min(ans,tmp);
  }
  cout << ans << endl;
}
