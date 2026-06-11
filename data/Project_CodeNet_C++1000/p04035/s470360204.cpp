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
  ll n,l,ans_i=-1;
  cin >> n >> l;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=0;i<n-1;i++){
    if(a[i]+a[i+1]>=l){
      ans_i=i;
      break;
    }
  }
  if(ans_i==-1){
    cout <<"Impossible"<<endl;
  }else{
    cout <<"Possible"<<endl;
    for(int i=0;i<ans_i;i++){
      cout << i+1<<endl;
    }
    for(int i=n-2;i>ans_i;i--){
      cout << i+1<<endl;
    }
    cout << ans_i+1<<endl;
  }
}
