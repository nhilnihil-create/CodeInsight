// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,t_size,chx;
  cin >> n;
  ll a[n];
  map<ll,ll> mp;
  t_size = 0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    mp[a[i]]++;
    t_size = max(a[i],t_size);
  }
  if(t_size%2==1) chx = (t_size+1)/2;
  else chx = t_size/2+1;
  for(int i=t_size;i>=chx;i--){
    if(mp[i]<2){
      cout <<"Impossible\n";
      return 0;
    }else{
      mp[i]-=2;
    }
  }
  if(t_size%2==0){
    if(mp[t_size/2]!=1){
      cout <<"Impossible\n";
      return 0;
    }else{
      mp[t_size/2]--;
    }
    chx--;
  }
  if(t_size%2==1) chx = (t_size+1)/2;
  else t_size = t_size/2;
  for(int i = chx;i>=1;i--){
    if(mp[i]>=1){
      cout <<"Impossible\n";
      return 0;
    }
  }
  cout <<"Possible\n";
}
