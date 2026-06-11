#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main() {
  ll n,l,t,x;
  ll x0,w0;
  int w;
  ll count=0;
  ll sw;
  vector<pair<ll,int>> ans;
  vector<pair<ll,int>> ri;
  vector<pair<ll,int>> le;
  vector<pair<ll,int>> all;
  cin>>n>>l>>t;
  vector<ll> nans(n,0);
  for(int i=0;i<n;i++){
    cin>>x>>w;
    if(i==0){
      x0=x;
      w0=w;
    }
    if(w==1) le.emplace_back(pair(x,i));
    else ri.emplace_back(pair(x,i)); 
    all.emplace_back(pair(x,i));
  }
  sort(all.begin(),all.end());
  for(int i=0;i<n;i++){
    if(w0==1){
      if((int)ri.size()<=i)break;
      count+=(2*t/l+(((l+ri[i].first-x0)%l)<(2*t%l)));

    }else{
      if((int)le.size()<=i)break;
      count+=(2*t/l+(((l-le[i].first+x0)%l)<=(2*t%l)));
    }
  }
  if(w0==1){
    sw=count%n;
  }else{
    sw=(n-count%n)%n;
  }

  for(pair<ll,int> x:le){
    ans.emplace_back(pair((x.first+t)%l,x.second));
  }
  for(pair<ll,int> x:ri){
    ans.emplace_back(pair((l-(l-x.first+t)%l)%l,x.second));    
  }


  sort(ans.begin(),ans.end());
  int key1,key2;
  for(int i=0;i<n;i++){
    if(ans[i].second==0)key1=i;  
  }
  for(int i=0;i<n;i++){
    if(all[i].second==0)key2=i;  
  }
  for(int i=0;i<n;i++){
    nans[all[(key2+i+sw)%n].second]=ans[(i+key1)%n].first;
  }
  
  for(int i=0;i<n;i++){
    cout<<nans[i]<<endl;
  }
  
  return 0;
}