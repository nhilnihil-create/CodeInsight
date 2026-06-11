#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
signed main(){
  string s;cin>>s;
  int res=0;
  int n=(int)s.length();
  int par=0;int gu=0;
  rep(i,n){
    if(i<=(n+1)/2-1){
      if(s[i]=='p')res--;
    }
    else{
      if(s[i]=='g')res++;
    }
  }
  cout<<res<<endl;
  return 0;
}
