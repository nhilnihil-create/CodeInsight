#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using datas=pair<ll,ll>;

int main(){
  ll N,W,a,b,ans=0;
  cin>>N>>W;
  set<ll> se;
  map<datas,ll> mp;
  queue<ll> que;
  se.insert(0);
  for(ll i=1;i<=N;i++){
    cin>>a>>b;
    for(auto j:se){
      if(j+a<=W){
        if(!mp[datas(i-1,j+a)])que.push(j+a);
        mp[datas(i,j+a)]=max(mp[datas(i-1,j+a)],mp[datas(i-1,j)]+b);
      }
      mp[datas(i,j)]=max(mp[datas(i,j)],mp[datas(i-1,j)]);
    }
    while(!que.empty()){
      auto x=que.front();que.pop();
      se.insert(x);
    }
  }
  for(auto i:se){
    ans=max(mp[datas(N,i)],ans);
  }
  cout<<ans<<endl;
  return 0;
}