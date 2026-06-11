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
  int n;cin>>n;
  vector<int> t(n);
  vector<int> a(n);
  rep(i,n)cin>>t[i]>>a[i];
  int res_t=t[0];int res_a=a[0];
  int buf_t=0;int buf_a=0;
  rep1(i,n-1){
    if(t[i]>=res_t&&a[i]>=res_a){
      res_t=t[i];res_a=a[i];
    }
    else{
      int k=max(res_t/t[i],res_a/a[i])-1;
      while(t[i]*k<res_t||a[i]*k<res_a){
        k++;
      }
      res_t=t[i]*k;res_a=a[i]*k;
    }
  }
  cout<<res_t+res_a<<endl;
  return 0;
}
