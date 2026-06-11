#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int n,m;
  cin>>n>>m;
  map<int,int> mp;
  rep(i,m){
    int a,b;
    cin>>a>>b;
    mp[a]++;
    mp[b]++;
  }
  bool ans=1;
  for(auto x : mp){
    if(x.second%2!=0) ans=0;
  }
  if(ans) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

