#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int h,w;
  cin>>h>>w;
  map<char,int> mp;
  rep(i,h)rep(j,w){
    char c; cin>>c;
    mp[c]++;
  }
  bool ans=1;
  bool odd=0;
  if(h%2==1 && w%2==1) odd=1;
  for(auto x : mp){
    if(x.second%2==1){
      if(odd){
        mp[x.first]--;
        odd=0;
      }
      else ans=0;
    }
  }
  int sec=0;
  if(h%2==1) sec+=w/2;
  if(w%2==1) sec+=h/2;
  for(auto x : mp){
    if(x.second%4!=0){
      if(sec>0)sec--;
      else ans=0;
    }
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}