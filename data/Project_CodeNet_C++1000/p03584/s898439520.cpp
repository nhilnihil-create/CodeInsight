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
#include<bitset>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
}
const ll MAX_B = 32;
signed main(){
  init_io();
  ll n,k,ans=0;
  cin >> n >> k;
  vector<ll> a(n),b(n);
  vector<vector<ll>> dp(MAX_B,vector<ll>(2,0));
  for(int i=0;i<n;i++){
    cin >> a[i] >> b[i];
  }
  for(int i=0;i<n;i++){
    if((a[i]|k) == k){
      ans += b[i];
    }
  }
  for(int r=0;r<MAX_B;r++){
    ll tmp = 0,tk=0;
    for(ll i=0;i<MAX_B;i++){
      if(i<r){
        tk += (1ll << i);
      }else if(i==r){
        if((k&(1ll << i))==0){
          tk = 0;
          break;
        }
      }else{
        tk += ((1ll << i) & k);
      }
    }
    for(int i=0;i<n;i++){
      if((a[i]|tk) == tk){
        tmp+=b[i];
      }
    }
    ans = max(tmp,ans);
  }
  cout << ans << endl;
}
