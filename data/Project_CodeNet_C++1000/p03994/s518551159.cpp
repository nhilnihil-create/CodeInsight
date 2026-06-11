#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
//#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
signed main(){
  string s;cin>>s;
  int k;cin>>k;
  int n=(int)s.length();
  vector<int> sub(n);
  vector<char> ans(n);
  rep(i,n){
    sub[i]='z'-s[i]+1;
    if(sub[i]<=k&&s[i]!='a'){
      k-=sub[i];
      ans[i]='a';
    }
    else{
      ans[i]=s[i];
    }
  }
  k%=26;
  ans[n-1]+=k;
  rep(i,n){
    cout<<ans[i];
  }
  cout<<endl;
  return 0;
}