// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
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
  ll n,cnt=0,dis=2;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  cnt += a[0]-1;
  for(int i=1;i<n;i++){
    if(a[i]==dis){
      dis++;
    }else{
      ll fd = dis;
      if(a[i]%dis==0){
        fd++;
      }
      if(a[i]<fd) continue;
      a[i] -= fd;
      cnt++;
      cnt += a[i]/dis;
    }
  }
  cout << cnt << endl;
}
