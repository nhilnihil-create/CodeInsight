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
using P=pair<int,int>;
using lint=long long;
using ll=long long;
const lint inf=1e18+7;
const int MOD=1000000007;
signed main(){
  int n;cin>>n;
  vector<int> a(n);
  rep(i,n)cin>>a[i];
  sort(a.begin(),a.end());
  bool flag;
  if(a[0]==a[n-1]){
    flag=a[0]<=n/2;
    if(a[0]==n-1)flag=true;
  }
  else{
    int ind=0;
    rep(i,n){
      if(a[i]!=a[0]){
        ind=i;
        break;
      }
    }
    int k=ind;
    flag=a[n-1]<=k+(n-k)/2;
    if(a[n-1]<k+1)flag=false;
    if(a[0]>k-1+(n-k)/2)flag=false;
    if(n-k<2)flag=false;
    if(a[0]!=a[n-1]-1)flag=false;
  }
	if(flag){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}
