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
  ll n,prev=0,set_v=100000000000;
  map<ll,ll> mp,mpv;
  cin >> n;
  vector<ll> a(n),ans(n,0);
  mp[0] = 0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(mp[a[i]]==0){
      mpv[a[i]] = i;
    }
    mp[a[i]]++;
  }
  vector<P> cpm(mp.begin(),mp.end());
  sort(cpm.begin(),cpm.end(),greater<P>());
  for(auto itr=cpm.begin();(itr+1)!=cpm.end();itr++){
    ll v = itr->first;
    ll nv = (itr+1)->first;
    ll dis =v-nv;
    set_v = min(set_v,mpv[v]);
    ans[set_v] += dis*(itr->second+prev);
    prev += itr->second;
  }
  for(auto i:ans){
    cout << i << endl;
  }
}
