#include<bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

const int mod=1000000007;

int main(){
  int n;
  cin>>n;
  string s1,s2;
  cin>>s1;
  cin>>s2;
  long long ans;
  if(s1[0]==s2[0]){
    ans=3;
    rep(i,1,n){
      if(s1[i]==s2[i]&&s1[i-1]==s2[i-1]){
        ans*=2;
        ans%=mod;
      }
      else if(s1[i]==s2[i]&&s1[i-1]!=s2[i-1]){
        ans%=mod;
      }
      else if(s1[i]!=s2[i]&&s1[i-1]==s2[i-1]){
        ans*=2;
        ans%=mod;
        ++i;
      }
      else if(s1[i]!=s2[i]&&s1[i-1]!=s2[i-1]){
        ans*=3;
        ans%=mod;
        ++i;
      }
    }
  }
  else{
    ans=6;
    rep(i,2,n){
      if(s1[i]==s2[i]&&s1[i-1]==s2[i-1]){
        ans*=2;
        ans%=mod;
      }
      else if(s1[i]==s2[i]&&s1[i-1]!=s2[i-1]){
        ans%=mod;
      }
      else if(s1[i]!=s2[i]&&s1[i-1]==s2[i-1]){
        ans*=2;
        ans%=mod;
        ++i;
      }
      else if(s1[i]!=s2[i]&&s1[i-1]!=s2[i-1]){
        ans*=3;
        ans%=mod;
        ++i;
      }
    }
  }
  cout<<ans<<endl;
}
      
      
  
