#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
signed main(){
  string s;cin>>s;
  int res=0;
  string ac="CODEFESTIVAL2016";
  rep(i,16){
    if(s[i]!=ac[i])res++;
  }
  cout<<res<<endl;
  return 0;
}
