#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  string s,t;
  cin>>n>>s>>t;
  int i=0;
  ll ans;
  bool p;
  if(s[0]==t[0]){
    ans=3;
    p=true;
    i++;
  }
  else{
    ans=6;
    p=false;
    i+=2;
  }
  while(i<n){
    if(s[i]==t[i]){
      if(p){
        ans*=2;
        ans%=mod;
      }
      p=true;
      i++;
    }
    else{
      if(p){
        ans*=2;
        ans%=mod;
      }
      else{
        ans*=3;
        ans%=mod;
      }
      p=false;
      i+=2;
    }
  }
  cout<<ans<<endl;
}