#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef deque<ll> V;
V dfs(ll n){
  if(n==1)return V();
  V res=dfs(n/2),t;
  res.push_back(res.size()+1);
  if(n%2)res.push_front(res.size()+1);
  return res;
}

int main(){
  ll n;
  cin>>n;
  V res=dfs(n+1);
  cout<<res.size()*2<<endl;
  for(int i=1;i<=res.size();i++){
    cout<<i;
    if(i!=res.size())cout<<" ";
  }
  while(!res.empty())
    cout<<" "<<res.front(),res.pop_front();
  
  cout<<endl;
  return 0;
}