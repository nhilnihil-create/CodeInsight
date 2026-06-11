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
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(18);
}
signed main(){
  init_io();
  ll n,a,b,c,d;
  bool can = false;
  cin >> n >> a >> b >> c >> d;
  for(int i=0;i<n;i++){
    ll left=(-d)*i+(n-1-i)*c;
    ll right=(-c)*i+(n-1-i)*d;
    if(left<=b-a&&b-a<=right){
      can = true;
      break;
    }
  }
  if(can){
    cout <<"YES\n";
  }else{
    cout <<"NO\n";
  }
}
