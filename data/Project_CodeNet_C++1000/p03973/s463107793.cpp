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
  int n;cin>>n;
  vector<int> a(n);
  rep(i,n)cin>>a[i];
  //vector<int> dp(n+1,-1);
  int last=0;int res=0;
  rep(i,n){
    if(a[i]==last+1)last++;
    a[i]--;
    res+=a[i]/(last+1);
    if(i==0)last=1;
  }
  cout<<res<<endl;
  return 0;
}