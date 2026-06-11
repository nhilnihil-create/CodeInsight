#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
#define lint long long
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;

signed main(){
  int n;cin>>n;
  vector<P> a(n);
  rep(i,n){
    cin>>a[i].first;
    a[i].second=i+1;
  }
  sort(a.begin(),a.end());
  vector<int> sum(n);
  sum[0]=a[0].first;
  rep1(i,n-1){
    sum[i]=sum[i-1]+a[i].first;
  }
  vector<bool> ans(n,false);
  ans[n-1]=true;
  int res=0;
  for(int i=n-2;i>=0;--i){
    if(sum[i]*2>=a[i+1].first){
      ans[i]=ans[i+1];
    }
  }
  rep(i,n){
    if(ans[i])++res;
  }
  cout<<res<<"\n";
  return 0;
}
