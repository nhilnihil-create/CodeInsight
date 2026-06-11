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
  ll n,x,ans=0,a,b;
  cin >> n >> x;
  ans = n;
  a = max(x,n-x);
  b = min(x,n-x);
  while(true){
    ll add = a/b;
    ll r = a%b;
    ans += (2*b) * add;
    if(r == 0) ans -= b;
    a = b;
    b = r;
    if(b == 0) break;
  }
  cout << ans << endl;
}
