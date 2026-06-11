#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n; cin>>n;
  map<int,int> mp;
  rep(i,n){
    int a; cin>>a;
    if(mp[a]!=0){
      mp[a]=0;
    }else{
      mp[a]=1;
    }
  }
  int ans=0;
  for(auto x : mp){
    if(x.second==1){
      ans++;
    }
  }
  cout<<ans<<endl;
}