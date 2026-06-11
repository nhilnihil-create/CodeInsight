#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

const int mod=1e9+7;

int main(){
  int n;
  cin>>n;
  string s1,s2;
  cin>>s1>>s2;
  string p;
  for(int i=0;i<n;){
    if(s1[i]!=s1[i+1]){
      p+='a';
      i++;
    }else{
      p+='b';
      i+=2;
    }
  } 
  int m=p.size();
  ll ans;
  if(p[0]=='a') ans=3;
  else ans=6;
  rep(i,m-1){
    if(p[i]=='a') ans=ans*2%mod;
    else{
      if(p[i+1]=='a') continue;
      else ans=ans*3%mod;
    }
  }
  cout<<ans<<endl;
}